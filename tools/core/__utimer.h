#ifndef __UTIMER_H
#define __UTIMER_H

#include "__uinstance.h"
#include "../interfaces/runable.h"

namespace unity
{
namespace tools
{
namespace core
{
class __utimer: public __uinstance, protected interfaces::Runable
{
protected:
    __utimer();

public:
    ~__utimer();

    virtual void wait(int msec) = 0;
    virtual void repeat(int msec) = 0;
    virtual void exec() = 0;
    virtual RETURN_CODE stop();

    bool isRunning();
};
}
}
}

#endif // __UTIMER_H
