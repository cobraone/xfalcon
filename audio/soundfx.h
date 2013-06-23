#ifndef SOUNDFX_H
#define SOUNDFX_H

#include "audio/__svc_soundfx.h"

xfalcon::services::__svc_soundfx &soundfx();

#define soundfx soundfx()

#endif // SOUNDFX_H
