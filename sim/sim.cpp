#include "__svc_sim.h"

static xfalcon::services::__svc_sim *_sim = NULL;

xfalcon::services::__svc_sim &sim()
{
    _sim = (xfalcon::services::__svc_sim*)(xfalcon::services::__svc_sim::getInstance());
    return *_sim;
}
