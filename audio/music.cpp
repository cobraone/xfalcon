#include "__svc_music.h"

static xfalcon::services::__svc_music *_music = NULL;

xfalcon::services::__svc_music &music()
{
    _music = (xfalcon::services::__svc_music*)(xfalcon::services::__svc_music::getInstance());
    return *_music;
}
