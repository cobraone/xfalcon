#include "__svc_bus.h"

static xfalcon::services::__svc_bus *_bus = NULL;

xfalcon::services::__svc_bus &bus()
{
    _bus = (xfalcon::services::__svc_bus*)(xfalcon::services::__svc_bus::getInstance());
    return *_bus;
}
