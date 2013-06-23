#ifndef __SVC_VOLUME_H
#define __SVC_VOLUME_H

#include "tools/unity_engine.h"
#include "SDL_mixer.h"
#include "channels.h"

namespace xfalcon
{
namespace services
{
class __svc_volume: NEW__USERVICE__<__svc_volume>
{
    SET__USERVICE__<__svc_volume>;

private:
    int _volume__master;
    int _volume__music;
    int _volume__channels[CHANNEL_COUNT];

    __svc_volume();

    bool __valid_volume(int volume);
    bool __valid_channel(int channel);

public:
    virtual ~__svc_volume();

    const int volume_min;
    const int volume_max;

    RETURN_CODE init();

    RETURN_CODE setVolume_Master(int volume);
    RETURN_CODE setVolume_Channel(int channel, int volume);
    RETURN_CODE setVolume_Music(int volume);
    RETURN_CODE mute_Master();
    RETURN_CODE mute_Channel(int channel);
    RETURN_CODE mute_Music();
    RETURN_CODE demute_Master();
    RETURN_CODE demute_Channel(int channel);
    RETURN_CODE demute_Music();
    int getVolume_Master();
    int getVolume_Channel(int channel);
    int getVolume_Music();
};
}
}

#endif // __SVC_VOLUME_H
