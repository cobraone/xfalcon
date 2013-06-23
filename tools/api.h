#ifndef API_H
#define API_H

#include "unity_engine.h"

#ifdef UNITY_QT4
#include "tty/tty_qtextedit.h"
#include "timer/timer_qtimer.h"
#include "thread/thread_qthread.h"
#endif

namespace unity
{
namespace tools
{
#ifdef UNITY_QT4
typedef tty::tty_QTextEdit      Tty;
typedef timer::timer_QTimer     Timer;
typedef thread::thread_QThread  Thread;
#endif
}
}

#endif // API_H
