#include "__svc_video.h"

static xfalcon::services::__svc_video *_video = NULL;

xfalcon::services::__svc_video &video()
{
    _video = xfalcon::services::__svc_video::getInstance();
    return *_video;
}
