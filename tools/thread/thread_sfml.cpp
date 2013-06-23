#include "thread_sfml.h"
#include "xfalcon.h"

namespace unity
{
namespace tools
{
namespace thread
{
thread_SFML::thread_SFML(): _thread(&thread_SFML::__exec, this)
{
}

thread_SFML::~thread_SFML()
{
}

void thread_SFML::__exec()
{
    exec();
}

RETURN_CODE thread_SFML::start()
{
    if (!isRunning())
    {
        _thread.launch();
        return RC_SUCCESS;
    }

    return RC_FAILURE;
}

RETURN_CODE thread_SFML::stop()
{
    if (isRunning())
    {
        _thread.wait();
        return RC_SUCCESS;
    }

    return RC_FAILURE;
}

RETURN_CODE thread_SFML::pause()
{
    return RC_FAILURE;
}
}
}
}
