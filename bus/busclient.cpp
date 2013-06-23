#include "busclient.h"
#include "bus.h"
#include "tools/maths.h"

namespace xfalcon
{
namespace services
{
BusClient::BusClient(): thread_SFML()//_thread(&BusClient::__exec, this)
{
    _channels = 0;
    _killed = false;
    bus.__connect(this);
    thread_SFML::start();
}

BusClient::~BusClient()
{
    __kill();

    while(_in_frames.size() || _out_frames.size())
        exec();

    bus.__disconnect(this);
}

void BusClient::__setFrequency(uint freq)
{
    _freq = freq;
}

bool BusClient::__isListening(TChannel channel)
{
    return channel & _channels;
}

bool BusClient::__pushFrame(Frame* frame)
{
    if (__isListening(frame->channel))
    {
        _in_frames.push_back(frame);
        return true;
    }

    return false;
}

void BusClient::process(Frame* data)
{
//    delete data;
}

void BusClient::listen(TChannel channels)
{
    _channels = _channels | channels;
}

void BusClient::exec()
{
    while(!_killed)
    {
        busMutex.lock();

        if (_in_frames.size())
        {
            TFrame* _frame = _in_frames.front();
            process(_frame);

            _frame->targets--;

            if (!_frame->targets)
                delete _frame;

            _in_frames.erase(_in_frames.begin());
        }

        if (_out_frames.size())
        {
            bus.__write(_out_frames.front());
            _out_frames.erase(_out_frames.begin());
        }

        busMutex.unlock();
        sf::sleep(sf::milliseconds(1)); // TODO prendre en compte la freq
    }
}

void BusClient::__kill()
{
    _killed = true;
}
}
}
