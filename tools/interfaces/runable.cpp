#include "runable.h"
#include "tools/exceptions.h"

unity::tools::interfaces::Runable::Runable()
{
    _running = false;
    _paused = false;
}

unity::tools::interfaces::Runable::~Runable()
{
}

RETURN_CODE unity::tools::interfaces::Runable::start()
{
    if (!_running)
    {
        _running = true;

        return RC_SUCCESS;
    }

    return RC_FAILURE;
}

RETURN_CODE unity::tools::interfaces::Runable::stop()
{
    if (_running)
    {
        _running = false;

        return RC_SUCCESS;
    }

    return RC_FAILURE;
}

RETURN_CODE unity::tools::interfaces::Runable::pause()
{
    if (!_paused)
        _paused = true;
    else
        _paused = false;

    return RC_SUCCESS;
}

bool unity::tools::interfaces::Runable::isPaused()
{
    return _paused;
}

bool unity::tools::interfaces::Runable::isRunning()
{
    return _running;
}
