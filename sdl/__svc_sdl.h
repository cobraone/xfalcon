#ifndef __SVC_SDL_H
#define __SVC_SDL_H

#include "tools/unity_engine.h"
#include <SDL.h>
#include "tools/thread/thread_qthread.h"
#include "tools/timer/timerloop.h"
#undef main

namespace xfalcon
{
namespace services
{
class __svc_SDL: NEW__USERVICE__<__svc_SDL>,
        //private unity::tools::thread::thread_QThread
        private unity::tools::timer::TimerLoop
{
    SET__USERVICE__<__svc_SDL>;

private:
    __svc_SDL();

    void exec();

public:
    virtual ~__svc_SDL();
    //void init();

    RETURN_CODE init();
    RETURN_CODE start();
};
}
}

#endif // __SVC_SDL_H
