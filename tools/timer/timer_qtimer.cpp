#include "timer_qtimer.h"
#include "tools/console.h"

namespace unity
{
namespace tools
{
namespace timer
{
timer_QTimer::timer_QTimer(): __utimer()
{
    _timer = new QTimer();
    connect(_timer, SIGNAL(timeout()), this, SLOT(exec()));
}

timer_QTimer::~timer_QTimer()
{
    delete _timer;
}

void timer_QTimer::wait(int msec)
{
    _timer->setSingleShot(true);
    _timer->start(msec);

    if (_timer->isActive())
        this->start();
}

void timer_QTimer::repeat(int msec)
{
    _timer->setSingleShot(false);
    _timer->start(msec);

    if (_timer->isActive())
        this->start();
}

void timer_QTimer::exec()
{
    if (_timer->isSingleShot())
        Runable::stop();
}

RETURN_CODE timer_QTimer::stop()
{
    if (isRunning())
    {
        _timer->stop();

        if (!_timer->isActive())
            Runable::stop();
    }

    return !isRunning();
}
}
}
}
