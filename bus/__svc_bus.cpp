#include "__svc_bus.h"
#include "tools/maths.h"
#include "busmutex.h"

namespace xfalcon
{
namespace services
{
__svc_bus::__svc_bus(): __USERVICE__("__svc_bus", M__VOLATILE),
    thread_SFML()
{
    setControls(START);

    _byte_counter = 0;
    _time_begin  = time.getTime();
    _freq = BUS_FREQUENCY_MAX / BUS_FREQUENCY;

    console() << "Bus frequency : " << BUS_FREQUENCY << "hz\n";
    start();
}

__svc_bus::~__svc_bus()
{
    for(uint i = 0; i < _nodes.size(); ++i)
        delete _nodes[i];
}

RETURN_CODE __svc_bus::start()
{
    thread_SFML::start();
    return __USERVICE__::start();
}

bool __svc_bus::__isValidChannel(int channel)
{
    return isPowerOfTwo(channel);
}

void __svc_bus::__setClientFreq()
{
    for(uint i = 0; i < _nodes.size(); ++i)
    _nodes[i]->__setFrequency(__getClientFreq());
}

void __svc_bus::__connect(BusClient *node)
{
    _nodes.push_back(node);
    __setClientFreq();
}

void __svc_bus::__disconnect(BusClient *node)
{
    uint i = 0;

    while(_nodes[i] != node && i < _nodes.size())
        i++;

    if (i < _nodes.size())
    {
        _nodes.erase(_nodes.begin() + i);
        __setClientFreq();
    }
}

void __svc_bus::__write(Frame* frame)
{
    busMutex.lock();

    if (frame->priority == PRIORITY_LOW)
        _frames.push_back(frame);
    else
        if (frame->priority == PRIORITY_HIGH)
            _frames.push_front(frame);

    _byte_counter += frame->size;

    busMutex.unlock();
}

void __svc_bus::exec()
{
    while(__USERVICE__::isRunning())
    {
        busMutex.lock();

        if (_frames.size())
            {
                for(uint i = 0; i < _nodes.size(); ++i)
                    if (_nodes[i] != _frames[0]->source)
                    {
                        _frames[0]->targets = __getClientsForChannel(_frames[0]->channel) - 1;
                        _nodes[i]->__pushFrame(_frames[0]);
                    }

                _frames.erase(_frames.begin());
            }

        busMutex.unlock();
        sf::sleep(sf::milliseconds(_freq));
    }
}


void __svc_bus::stats()
{
    float _avg_load;
    float _cli_freq;

    _avg_load = _byte_counter * 8 / (time.getTime() - _time_begin);
    _cli_freq = BUS_FREQUENCY_MAX / __getClientFreq();

    console() << "Bus Statistics :\n";
    console() << "Transferred...... : " << _byte_counter << " bytes\n";
    console() << "Average Load..... : " << (_avg_load / 1000) << " kbps\n";
    console() << "Clients.......... : " << _nodes.size() << "\n";
    console() << "Client freqency.. : " << _cli_freq << "hz\n";
}

uint __svc_bus::__getClientFreq()
{
    return _nodes.size();
}

uint __svc_bus::__getClientsForChannel(TChannel channel)
{
    uint i = 0;

    for(uint j = 0; j < _nodes.size(); ++j)
        i += _nodes[j]->__isListening(channel);

    return i;
}
}
}
