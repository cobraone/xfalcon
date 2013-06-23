#include "__svc_soundfx.h"
#include "config/config.h"
#include "channels.h"
#include "audio.h"
#include "volume.h"
#include "tools/utils/substrings.h"
#include <fstream>
#include "bus/bus.h"

using namespace unity::tools::utils;

namespace xfalcon
{
namespace services
{
__svc_soundfx::__svc_soundfx(): __uservice("__svc_soundfx", M__VOLATILE)
{
    dependsOn(&audio);
    dependsOn(&volume);
    setControls(INIT);
}

RETURN_CODE __svc_soundfx::init()
{
    if (INIT__USERVICE__)
    {
        __load_soundfxlist(config.paths[SOUNDFX] + config.soundfx[SFX_LIST]);

        return RC_SUCCESS;
    }

    return RC_FAILURE;
}

void __svc_soundfx::__load_soundfxlist(const string &filename)
{
    ifstream _file(filename);

    console() << MSG__LOAD << "soundfx list \"" << filename << "\"...";

    if (_file)
    {
        console() << MSG__OK;
        str _line;

        while(getline(_file, _line))
            if (_line[0] != '#')
                __load_soundfx(_line);
    }
    else
        error(E__FILE_NOT_FOUND);
}

void __svc_soundfx::__load_soundfx(const string &data)
{
    SubStrings _sstr(data, ',');

    str _id = _sstr.getFirst();
    str _filename = _sstr.getNext();
    str _channel = _sstr.getNext();
    SoundFX *_sfx = new SoundFX();

    _sfx->sound = Mix_LoadWAV(_filename.c_str());
    _sfx->channel = atoi(_channel.c_str());
    _sfxlist.add(_id, _sfx);
}

RETURN_CODE __svc_soundfx::play(str soundId)
{
    CHECK__USERVICE__

    SoundFX *_sfx = _sfxlist.getData(soundId);
    Mix_PlayChannel(_sfx->channel, _sfx->sound, 0);
}

void __svc_soundfx::process(Frame data)
{
    //console() << getName() << " received: " << data.data << "\n";
}
}
}
