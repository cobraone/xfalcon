#include "configurable.h"

namespace unity
{
namespace tools
{
namespace interfaces
{
Configurable::Configurable()
{
    _isInit = false;
}

Configurable::~Configurable()
{
}

bool Configurable::isInit()
{
    return _isInit;
}

RETURN_CODE Configurable::init()
{
    if (!isInit())
    {
        _isInit = true;
        return RC_SUCCESS;
    }

    return RC_FAILURE;
}
}
}
}
