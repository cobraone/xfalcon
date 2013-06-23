#include "__utimer.h"

namespace unity
{
namespace tools
{
namespace core
{
__utimer::__utimer(): Runable()
{
}

__utimer::~__utimer()
{
}

bool __utimer::isRunning()
{
    return Runable::isRunning();
}

RETURN_CODE __utimer::stop()
{
    return Runable::stop();
}
}
}
}
