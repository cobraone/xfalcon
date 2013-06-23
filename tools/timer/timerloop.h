#ifndef TIMERLOOP_H
#define TIMERLOOP_H

//#include "tools/core/__uTimer.h"
//#include "tools/timer/timer_qtimer.h"
#include "../api.h"
#include "tools/interfaces/loop.h"

namespace unity
{
namespace tools
{
namespace timer
{
class TimerLoop: protected Timer, public interfaces::Loop//protected timer::timer_QTimer
{
private:
    uint _msec;

protected:
    TimerLoop();

public:
    ~TimerLoop();

    RETURN_CODE start();
    RETURN_CODE stop();
    RETURN_CODE pause();

    void setSpeed_int(uint msec);
    void setSpeed_lps(uint lps);

private slots:
    virtual void exec() = 0;
};
}
}
}

#endif // TIMERLOOP_H
