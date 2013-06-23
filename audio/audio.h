#ifndef AUDIO_H
#define AUDIO_H

#include "audio/__svc_audio.h"

xfalcon::services::__svc_audio &audio();

#define audio audio()

#endif // AUDIO_H
