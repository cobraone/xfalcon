#include "__uthread.h"

namespace unity
{
namespace tools
{
namespace core
{
__uthread::__uthread(): __uinstance(), Runable()
{
}

__uthread::~__uthread()
{
}

RETURN_CODE __uthread::start()
{
    return Runable::start();
}

RETURN_CODE __uthread::stop()
{
    return Runable::stop();
}

RETURN_CODE __uthread::pause()
{
    return Runable::pause();
}

bool __uthread::isRunning()
{
    return Runable::isRunning();
}

bool __uthread::isPaused()
{
    return Runable::isPaused();
}
}
}
}
