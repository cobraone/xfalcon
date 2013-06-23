#ifndef RUNABLE_H
#define RUNABLE_H

#include "tools/return.h"

namespace unity
{
namespace tools
{
namespace interfaces
{
class Runable
{
private:
    bool _running;
    bool _paused;

protected:
    Runable();
    ~Runable();

public:
    RETURN_CODE start();
    RETURN_CODE stop();
    RETURN_CODE pause();

    bool isRunning();
    bool isPaused();
};
}
}
}

#endif // RUNABLE_H
