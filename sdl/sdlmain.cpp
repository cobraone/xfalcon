#include "sdlmain.h"

static xfalcon::services::__svc_SDL *_sdl = NULL;

xfalcon::services::__svc_SDL &SDL()
{
    _sdl = xfalcon::services::__svc_SDL::getInstance();
    return *_sdl;
}
