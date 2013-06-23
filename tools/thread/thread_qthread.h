#ifndef THREAD_QTHREAD_H
#define THREAD_QTHREAD_H

#include <QObject>
#include <QThread>
#include "tools/interfaces/runable.h"

namespace unity
{
namespace tools
{
namespace thread
{
class thread_QThread: public QObject, public interfaces::Runable
{
    Q_OBJECT

private:
    QThread *_thread;

public:
    thread_QThread();
    ~thread_QThread();

private slots:
    void __exec();

public:
    virtual void exec() = 0;
    virtual RETURN_CODE start();
    virtual RETURN_CODE stop();
    virtual RETURN_CODE pause();
};
}
}
}

#endif // THREAD_QTHREAD_H
