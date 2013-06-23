#include "__svc_audio.h"

static xfalcon::services::__svc_audio *_audio = NULL;

xfalcon::services::__svc_audio &audio()
{
    _audio = (xfalcon::services::__svc_audio*)(xfalcon::services::__svc_audio::getInstance());
    return *_audio;
}
