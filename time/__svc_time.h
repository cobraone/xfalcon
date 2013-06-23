#ifndef __SVC_TIME_H
#define __SVC_TIME_H

#include "tools/unity_engine.h"
#include "tools/timer/timerloop.h"

namespace xfalcon
{
namespace services
{
class __svc_time: NEW__USERVICE__<__svc_time>
{
    SET__USERVICE__<__svc_time>;

private:
    class __timer: public unity::tools::timer::TimerLoop
    {
    public:
        uint _time;
        __timer();
        void exec();
    } _timer;

    __svc_time();

public:
    uint getTime();
};
}
}

#endif // __SVC_TIME_H
