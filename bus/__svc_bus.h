#ifndef __SVC_BUS_H
#define __SVC_BUS_H

#include "tools/unity_engine.h"
#include "tools/timer/timerloop.h"
#include "busdefine.h"
#include <vector>
#include "busdata.h"
#include "busclient.h"
#include "time/time.h"
#include <deque>
#include <SFML/System.hpp>
#include "../tools/thread/thread_sfml.h"

namespace xfalcon
{
namespace services
{
class __svc_bus: NEW__USERVICE__<__svc_bus>,
    private unity::tools::thread::thread_SFML
{
    SET__USERVICE__<__svc_bus>;
    friend class BusClient;

private:
    uint _byte_counter;
    uint _time_begin;
    uint _freq; 

    std::vector<BusClient*> _nodes;
    std::deque<Frame*> _frames;

    __svc_bus();

    void __connect(BusClient *node);
    void __disconnect(BusClient *node);
    void __write(Frame* frame);
    bool __isValidChannel(int channel);
    uint __getClientFreq();     // TODO a rendre publique pour GLLOOP
    void __setClientFreq();
    uint __getClientsForChannel(TChannel channel);
    void exec();

public:
    ~__svc_bus();

    RETURN_CODE start();

    void stats();
};
}
}

#endif // __SVC_BUS_H
