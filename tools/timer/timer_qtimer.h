#ifndef TIMER_QTIMER_H
#define TIMER_QTIMER_H

#include <QTimer>
#include <QObject>
#include "../core/__utimer.h"

namespace unity
{
namespace tools
{
namespace timer
{
class timer_QTimer: public QObject, public core::__utimer
{
    Q_OBJECT

private:
    QTimer *_timer;

public:
    timer_QTimer();
    ~timer_QTimer();

    void wait(int msec);
    void repeat(int msec);
    RETURN_CODE stop();

protected slots:
    virtual void exec();
};
}
}
}

#endif // TIMER_QTIMER_H
