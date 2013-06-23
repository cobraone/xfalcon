#ifndef __SVC_CONFIG_H
#define __SVC_CONFIG_H

#include "tools/unity_engine.h"
#include "settings.h"
#include "datatypes.h"

namespace xfalcon
{
namespace services
{
class __svc_config: NEW__USERVICE__<__svc_config>
{
    SET__USERVICE__<__svc_config>;

private:
    __svc_config();
    ~__svc_config();

    void __load_paths();
    void __load_videoconfig();
    void __load_musicconfig();
    void __load_volumeconfig();
    void __load_soundfxconfig();

public:
    configtools::Settings<str> paths;
    configtools::Settings<int> video;
    configtools::Settings<str> music;
    configtools::Settings<int> volume;
    configtools::Settings<str> soundfx;

    RETURN_CODE init();
};
}
}

#endif // __SVC_CONFIG_H
