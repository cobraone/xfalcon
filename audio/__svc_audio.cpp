#include "__svc_audio.h"
#include <SDL.h>
#include "SDL_mixer.h"
#include "sdl/sdlmain.h"

namespace xfalcon
{
namespace services
{
__svc_audio::__svc_audio(): __USERVICE__("__svc_audio", M__VOLATILE)
{
    dependsOn(&SDL());
    setControls(INIT);
}

__svc_audio::~__svc_audio()
{
    //Mix_FreeMusic(_music);
    Mix_CloseAudio();
    //SDL_Quit();
}

RETURN_CODE __svc_audio::init()
{
    if (INIT__USERVICE__)
    {
        console() << MSG__TAB4 << MSG__INITIALIZE << "SDL_AUDIO... ";

//        if (SDL_Init(SDL_INIT_AUDIO) != 1)
        {
            console() << MSG__OK
                      << MSG__TAB4 << MSG__INITIALIZE << "SDL_MIXER... ";

            if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) != -1)
            {
                console() << MSG__OK;
                return RC_SUCCESS;
            }
        }
    }

    return RC_FAILURE;
}
}
}
