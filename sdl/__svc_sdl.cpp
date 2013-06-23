#include "__svc_sdl.h"
#include "../xfalcon.h"

namespace xfalcon
{
namespace services
{
__svc_SDL::__svc_SDL(): __uservice("__svc_SDL", M__VOLATILE)
{
    setControls(INIT|START);
    setSpeed_int(1000);
}

__svc_SDL::~__svc_SDL()
{
    SDL_Quit();
}

void __svc_SDL::exec()
{
    SDL_Event _event;
    SDL_Event _event2;
    console() << "wait\n";

    _event2.type = SDL_KEYDOWN;

    SDL_PushEvent(&_event2);


    //while(__USERVICE__::isRunning())
        while(SDL_PollEvent(&_event))
        {
            switch(_event.type)
            {
            case SDL_KEYDOWN:
                console() << "keydown\n"; break;
            default:
                break;
            }
        }
}

RETURN_CODE __svc_SDL::init()
{
    if (INIT__USERVICE__)
    {
        SDL_Init(SDL_INIT_AUDIO);
        return true;
    }

    return false;
}

RETURN_CODE __svc_SDL::start()
{
    if (START__USERVICE__)
    {
        SDL_Init(SDL_INIT_VIDEO);
        TimerLoop::start();
        return RC_SUCCESS;
    }

    return RC_FAILURE;
}
}
}


