#include "__svc_config.h"

static xfalcon::services::__svc_config *_config = NULL;

xfalcon::services::__svc_config &config()
{
    _config = (xfalcon::services::__svc_config*)(xfalcon::services::__svc_config::getInstance());
    return *_config;
}
