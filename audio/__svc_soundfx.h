#ifndef __SVC_SOUNDFX_H
#define __SVC_SOUNDFX_H

#include "tools/unity_engine.h"
#include "tools/containers/container_indexedlist.h"
#include "SDL_mixer.h"
#include "../bus/busclient.h"

using namespace unity::tools::interfaces;
using namespace std;

namespace xfalcon
{
namespace services
{
typedef struct
{
    Mix_Chunk *sound;
    uint channel;
} SoundFX;

class __svc_soundfx: NEW__USERVICE__<__svc_soundfx>, protected BusClient
{
    SET__USERVICE__<__svc_soundfx>;

private:
    unity::tools::containers::Container_IndexedList<SoundFX *> _sfxlist;

    __svc_soundfx();

    void __load_soundfx(const string &data);
    void __load_soundfxlist(const string &filename);

    void process(Frame data);

public:
    RETURN_CODE init();
    RETURN_CODE play(str soundId);
};
}
}

#endif // __SVC_SOUNDFX_H
