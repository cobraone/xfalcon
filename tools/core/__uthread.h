#ifndef __UTHREAD_H
#define __UTHREAD_H

#include "__uinstance.h"
#include "../interfaces/runable.h"

namespace unity
{
namespace tools
{
namespace core
{
class __uthread: public __uinstance, interfaces::Runable
{
protected:
    __uthread();

public:
    ~__uthread();

    virtual RETURN_CODE start();
    virtual RETURN_CODE stop();
    virtual RETURN_CODE pause();

    bool isRunning();
    bool isPaused();

private:
    virtual void exec() = 0;
};
}
}
}

#endif // __UTHREAD_H
