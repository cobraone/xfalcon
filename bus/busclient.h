#ifndef BUSCLIENT_H
#define BUSCLIENT_H

#include "busdata.h"
#include <vector>
#include "tools/timer/timerloop.h"
#include "bustypes.h"
#include "busdefine.h"
#include "SFML/System.hpp"
#include "busmutex.h"
#include "../tools/thread/thread_sfml.h"

namespace xfalcon
{
namespace services
{
class __svc_bus;

class BusClient: private unity::tools::thread::thread_SFML
{
    friend class __svc_bus;

private:
    TChannel    _channels;
    bool _killed;
    uint _freq;
    std::vector<TFrame*> _in_frames;
    std::vector<TFrame*> _out_frames;

    bool __pushFrame(Frame* frame);
    bool __isListening(TChannel channel);
    void exec();
    void __kill();
    void __setFrequency(uint freq);

protected:
    BusClient();
    ~BusClient();

    virtual void process(Frame* data);

    template <typename T> T* getData(Frame* frame)
    {
        BusData<T>* _bd = static_cast<BusData<T>* >(frame);
        return &(_bd->data);
    }
	
	template <typename T> TType getType(Frame *frame)
	{
		BusData<T>* _bd = static_cast<BusData<T>* >(frame);
		return _bd->type;
	}
public:
    void listen(TChannel channels);

    template <typename T> void broadcast(TChannel channel, TType type, const T &data, PriorityFlag priority = PRIORITY_LOW)
    {
        busMutex.lock();
        BusData<T> *_bd = new BusData<T>();

        _bd->channel = channel;
        _bd->data = data;
        _bd->type = type;
        _bd->size = sizeof(T);
        _bd->source = this;
        _bd->priority = priority;

        //busMutex.lock();
        _out_frames.push_back(_bd);
        busMutex.unlock();
    }
};
}
}

#endif // BUSCLIENT_H
