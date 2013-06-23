#include "__svc_config.h"
#include "params.h"
#include "paths.h"

namespace xfalcon
{
namespace services
{
__svc_config::__svc_config(): __uservice("__svc_config", M__VOLATILE)
{
    setControls(INIT);
    init();
}

__svc_config::~__svc_config()
{
}

RETURN_CODE __svc_config::init()
{
    if (INIT__USERVICE__)
    {
        __load_paths();
        __load_videoconfig();
        __load_musicconfig();
        __load_volumeconfig();
        __load_soundfxconfig();

        return RC_SUCCESS;
    }

    return RC_FAILURE;
}

void __svc_config::__load_paths()
{
    console() << "Setting default paths... ";

    paths.add(DIR__CONFIG)
            .add(DIR__SOUNDFX)
            .add(DIR__MUSIC);

    console() << "\n";
}

void __svc_config::__load_videoconfig()
{
    console() << "Setting video config... ";

    video.add(PARAM_SIZEX)
            .add(PARAM_SIZEY)
            .add(PARAM_BPP)
            .add(PARAM_RENDERMODE);

    console() << "\n";
}

void __svc_config::__load_musicconfig()
{
    console() << "Setting music config... ";

    music.add(PARAM_MUSIC_SOURCE);

    console() << "\n";
}

void __svc_config::__load_volumeconfig()
{
    console() << "Setting volume config... ";

    volume.add(PARAM_VOLUME_DEFAULT)
          .add(PARAM_VOLUME_MAX)
          .add(PARAM_VOLUME_MIN)
          .add(PARAM_VOLUME_COCKPIT)
          .add(PARAM_VOLUME_COMMS)
          .add(PARAM_VOLUME_ENGINE)
          .add(PARAM_VOLUME_FLIGHT)
          .add(PARAM_VOLUME_RWR)
          .add(PARAM_VOLUME_SIDEWINDER)
          .add(PARAM_VOLUME_SOUNDFX);

    console() << "\n";
}

void __svc_config::__load_soundfxconfig()
{
    console() << "Setting soundfx config... ";

    soundfx.add(PARAM_SFX_LIST);

    console() << "\n";
}
}
}
