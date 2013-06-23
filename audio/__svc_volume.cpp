#include "__svc_volume.h"
#include "audio.h"
#include "SDL_mixer.h"
#include "channels.h"
#include "../config/config.h"

namespace xfalcon
{
namespace services
{
__svc_volume::__svc_volume(): __USERVICE__("__svc_volume", M__VOLATILE),
    volume_min(/*0),*/config.volume[VOLUME_MIN]),
    volume_max(/*128)*/config.volume[VOLUME_MAX])
{
    dependsOn(&config);
    dependsOn(&audio);
    setControls(INIT);
}

__svc_volume::~__svc_volume()
{
}

RETURN_CODE __svc_volume::init()
{
    if (INIT__USERVICE__)
    {
        Mix_AllocateChannels(CHANNEL_COUNT);

        setVolume_Master(config.volume[VOLUME_MAX]);
        setVolume_Music(config.volume[VOLUME_DEFAULT]);

        setVolume_Channel(CHANNEL_ENGINE, config.volume[VOLUME_ENGINE]);
        setVolume_Channel(CHANNEL_SIDEWINDER, config.volume[VOLUME_SIDEWINDER]);
        setVolume_Channel(CHANNEL_RWR, config.volume[VOLUME_RWR]);
        setVolume_Channel(CHANNEL_COCKPIT, config.volume[VOLUME_COCKPIT]);
        setVolume_Channel(CHANNEL_COMMS, config.volume[VOLUME_COMMS]);
        setVolume_Channel(CHANNEL_FLIGHT, config.volume[VOLUME_FLIGHT]);
        setVolume_Channel(CHANNEL_SOUNDFX, config.volume[VOLUME_SOUNDFX]);

        return RC_SUCCESS;
    }

    return RC_FAILURE;
}

RETURN_CODE __svc_volume::setVolume_Master(int volume)
{
    CHECK__USERVICE__

    if (__valid_volume(volume))
    {
        int _range = 100 * volume / volume_max;
        console() << "Setting master volume to " << _range << "%\n";
        Mix_VolumeMusic(_volume__music * _range / 100);

        for(uint i = 0; i < CHANNEL_COUNT; ++i)
            Mix_Volume(i, _volume__channels[i] * _range / 100);

        _volume__master = volume;

        //Mix_Volume(CHANNEL_ALL, volume);
        //setVolume_Music(volume);
        return RC_SUCCESS;
    }
    else
        return RC_FAILURE;
}

RETURN_CODE __svc_volume::setVolume_Music(int volume)
{
    CHECK__USERVICE__

    if (__valid_volume(volume))
    {
        console() << "Setting music volume to " << 100 * volume / volume_max << "%\n";
        Mix_VolumeMusic(volume * _volume__master / volume_max);
        _volume__music = volume;

        return RC_SUCCESS;
    }
    else
        return RC_FAILURE;
}

RETURN_CODE __svc_volume::setVolume_Channel(int channel, int volume)
{
    CHECK__USERVICE__

    if (__valid_volume(volume) && __valid_channel(channel))
    {
        console() << "Setting channel " << channel << " volume to " << 100 * volume / volume_max << "%\n";
        Mix_Volume(channel, volume * _volume__master / volume_max);
        _volume__channels[channel] = volume;

        return RC_SUCCESS;
    }
    else
        return RC_FAILURE;
}

RETURN_CODE __svc_volume::mute_Master()
{
    CHECK__USERVICE__

    RETURN_CODE _rc = RC_SUCCESS;

    for(uint i = 0; i < CHANNEL_COUNT; ++i)
        _rc = _rc && mute_Channel(i);

    return _rc && mute_Music();
}

RETURN_CODE __svc_volume::mute_Channel(int channel)
{
    CHECK__USERVICE__

    if (__valid_channel(channel))
    {
        Mix_Volume(channel, 0);
        return RC_SUCCESS;
    }

    return RC_FAILURE;
}

RETURN_CODE __svc_volume::mute_Music()
{
    CHECK__USERVICE__

    Mix_VolumeMusic(0);

    return RC_SUCCESS;
}

RETURN_CODE __svc_volume::demute_Master()
{
    CHECK__USERVICE__

    RETURN_CODE _rc = RC_SUCCESS;

    for(int i = 0; i < CHANNEL_COUNT; ++i)
        _rc = _rc && demute_Channel(i);

    _rc = _rc && demute_Music();

    return _rc && setVolume_Master(_volume__master);
}

RETURN_CODE __svc_volume::demute_Channel(int channel)
{
    CHECK__USERVICE__

    if (__valid_channel(channel))
        return setVolume_Channel(channel, _volume__channels[channel]);

    return RC_FAILURE;
}

RETURN_CODE __svc_volume::demute_Music()
{
    return setVolume_Music(_volume__music);
}

int __svc_volume::getVolume_Master()
{
    return _volume__master;
}

int __svc_volume::getVolume_Channel(int channel)
{
    return _volume__channels[channel];
}

int __svc_volume::getVolume_Music()
{
    return Mix_VolumeMusic(-1);
}

bool __svc_volume::__valid_volume(int volume)
{
    return (volume >= volume_min) && (volume <= volume_max);
}

bool __svc_volume::__valid_channel(int channel)
{
    return (channel >= 0 && channel < CHANNEL_COUNT);
}
}
}
