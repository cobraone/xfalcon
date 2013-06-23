#include "__svc_soundfx.h"

static xfalcon::services::__svc_soundfx *_soundfx = NULL;

xfalcon::services::__svc_soundfx &soundfx()
{
    _soundfx = (xfalcon::services::__svc_soundfx*)(xfalcon::services::__svc_soundfx::getInstance());
    return *_soundfx;
}
