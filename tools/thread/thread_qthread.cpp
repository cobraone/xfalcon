#include "thread_qthread.h"
#include "xfalcon.h"
#include <QTimer>

namespace unity
{
namespace tools
{
namespace thread
{
thread_QThread::thread_QThread()
{
    _thread = new QThread(xfmain.getXfalconWnd());

    connect(_thread, SIGNAL(started()), this, SLOT(__exec()));
    connect(_thread, SIGNAL(finished()), this, SLOT(deleteLater()));

    this->moveToThread(_thread);
}

thread_QThread::~thread_QThread()
{
    delete _thread;
}

void thread_QThread::__exec()
{
    exec();
}

RETURN_CODE thread_QThread::start()
{
    if (!isRunning())
    {
        _thread->start();

        if (_thread->isRunning())
            return RC_SUCCESS;
    }

    return RC_FAILURE;
}

RETURN_CODE thread_QThread::stop()
{
    if (isRunning())
    {
        _thread->wait();
        return RC_SUCCESS;
    }

    return RC_FAILURE;
}

RETURN_CODE thread_QThread::pause()
{
    return RC_FAILURE;
}
}
}
}
