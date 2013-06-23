#include "__svc_graphics.h"

static xfalcon::services::__svc_graphics *_graphics = NULL;

xfalcon::services::__svc_graphics &graphics()
{
    _graphics = (xfalcon::services::__svc_graphics*)(xfalcon::services::__svc_graphics::getInstance());
    return *_graphics;
}
