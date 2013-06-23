#include "__svc_volume.h"

static xfalcon::services::__svc_volume *_volume = NULL;

xfalcon::services::__svc_volume &volume()
{
    _volume = (xfalcon::services::__svc_volume*)(xfalcon::services::__svc_volume::getInstance());
    return *_volume;
}

