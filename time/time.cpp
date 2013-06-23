#include "__svc_time.h"

static xfalcon::services::__svc_time *_time = NULL;

xfalcon::services::__svc_time &time()
{
    _time = (xfalcon::services::__svc_time*)(xfalcon::services::__svc_time::getInstance());
    return *_time;
}
