#include "__svc_xfalcon.h"

static xfalcon::services::__svc_xfalcon *_xfalcon = NULL;

xfalcon::services::__svc_xfalcon &xfmain()
{
    _xfalcon = (xfalcon::services::__svc_xfalcon*)(xfalcon::services::__svc_xfalcon::getInstance());
    return *_xfalcon;
}
