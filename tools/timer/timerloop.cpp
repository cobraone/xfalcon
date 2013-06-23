#include "timerloop.h"
#include "tools/console.h"

namespace unity
{
namespace tools
{
namespace timer
{
TimerLoop::TimerLoop(): timer_QTimer()
{
}

TimerLoop::~TimerLoop()
{
}

RETURN_CODE TimerLoop::start()
{
    repeat(_msec);
    return RC_SUCCESS;
}

RETURN_CODE TimerLoop::stop()
{
    return timer_QTimer::stop();
}

RETURN_CODE TimerLoop::pause()
{
    return RC_FAILURE;
}

void TimerLoop::setSpeed_int(uint msec)
{
    //warning("setSpeed_int", W__NOT_YET_IMPLEMENTED);
    _msec = msec;
}

void TimerLoop::setSpeed_lps(uint lps)
{
    warning("setSpeed_lps", W__NOT_YET_IMPLEMENTED);
}
}
}
}
