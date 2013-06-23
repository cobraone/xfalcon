#ifndef __SVC_SIM_H
#define __SVC_SIM_H

#include "tools/unity_engine.h"
#include "ui/xfwnd.h"
#include "ui/xfalcon_out.h"
#include "tools/timer/timerloop.h"

namespace xfalcon
{
namespace services
{
class __svc_sim: NEW__USERVICE__<__svc_sim>
{
    SET__USERVICE__<__svc_sim>;

private:
    class __SimLoop: public unity::tools::timer::TimerLoop
    {
        void exec();
    } __sim_loop;

    __svc_sim();
    ~__svc_sim();

public:
    RETURN_CODE init();
    RETURN_CODE start();
    RETURN_CODE pause();
    RETURN_CODE stop();
};
}
}

#endif // __SVC_SIM_H
