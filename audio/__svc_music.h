#ifndef __SVC_MUSIC_H
#define __SVC_MUSIC_H

#include "tools/unity_engine.h"
#include <SDL.h>
#undef main
#include "SDL_mixer.h"
#include <string>
#include <vector>
#include "tools/timer/timerloop.h"
#include "tools/containers/container_indexedlist.h"

using namespace unity::tools::timer;
using namespace unity::tools::interfaces;
using namespace unity::tools::containers;
using namespace std;

namespace xfalcon
{
namespace services
{
typedef Line<string, Mix_Music*> PlayLine;

class __svc_music: NEW__USERVICE__<__svc_music>, protected TimerLoop
{
    SET__USERVICE__<__svc_music>;

private:
    Container_IndexedList<Mix_Music *> __plist;

    Mix_Music *__music;

    __svc_music();

    void __loadMusic(const string &filename);
    void __loadPlayList(const string &filename);

public:
    virtual ~__svc_music();

    RETURN_CODE init();
    RETURN_CODE start();

    void exec();
};
}
}

#endif // __SVC_MUSIC_H
