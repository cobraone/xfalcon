#include "__svc_mouse.h"

static xfalcon::services::__svc_mouse *_mouse = NULL;

xfalcon::services::__svc_mouse &mouse()
{
    _mouse = (xfalcon::services::__svc_mouse*)(xfalcon::services::__svc_mouse::getInstance());
    return *_mouse;
}
