#ifndef PARAMS_H
#define PARAMS_H

#include "datatypes.h"
#include <SDL.h>
#include <SDL_mixer.h>

// --- IDENTIFIERS ---

#define SIZE_X              "VID__OUTWIDTH"
#define SIZE_Y              "VID__OUTHEIGHT"
#define BPP                 "VID__OUTBPP"
#define RENDERMODE          "VID__OUTSWHW"
#define MUSIC_SOURCE        "MUS__SOURCE"
#define VOLUME_DEFAULT      "VOL__DEFAULT"
#define VOLUME_MAX          "VOL__MAX"
#define VOLUME_MIN          "VOL__MIN"
#define VOLUME_ENGINE       "VOL__ENGINE"
#define VOLUME_SIDEWINDER   "VOL__SIDEWINDER"
#define VOLUME_RWR          "VOL__RWR"
#define VOLUME_COCKPIT      "VOL__COCKPIT"
#define VOLUME_COMMS        "VOL__COMMS"
#define VOLUME_FLIGHT       "VOL__FLIGHT"
#define VOLUME_SOUNDFX      "VOL__SOUNDFX"
#define SFX_RWR_MIG21       "SFX__RWR_MIG21"
#define SFX_LIST            "SFX__LIST"

// --- VALUES ---

#define MODE_SW             1
#define MODE_HW             2
#define SRC_FF6             "ff6"
#define SRC_F4              "f4"
#define SRC_ALL             "all"
#define VOL_MIN             0
#define VOL_MAX             MIX_MAX_VOLUME
#define VOL_AVG             VOL_MAX / 2
#define FIL_RWR_MIG21       "MIG21.wav"
#define FIL_PLAYLIST        "playlist.txt"
#define FIL_SFX_LIST        "soundfx.txt"

// --- PARAMETERS ---
// --- VIDEO ---

#define PARAM_SIZEX         INT_DATA ( SIZE_X       , 640            )
#define PARAM_SIZEY         INT_DATA ( SIZE_Y       , 480            )
#define PARAM_BPP           INT_DATA ( BPP          , 32             )
#define PARAM_RENDERMODE    INT_DATA ( RENDERMODE   , MODE_HW        )

// --- MUSIC ---

#define PARAM_MUSIC_SOURCE  STR_DATA ( MUSIC_SOURCE , SRC_F4         )

// --- VOLUME ---

#define PARAM_VOLUME_DEFAULT    INT_DATA ( VOLUME_DEFAULT   , VOL_AVG   )
#define PARAM_VOLUME_MIN        INT_DATA ( VOLUME_MIN       , VOL_MIN   )
#define PARAM_VOLUME_MAX        INT_DATA ( VOLUME_MAX       , VOL_MAX   )
#define PARAM_VOLUME_ENGINE     INT_DATA ( VOLUME_ENGINE    , VOL_MAX   )
#define PARAM_VOLUME_SIDEWINDER INT_DATA ( VOLUME_SIDEWINDER, VOL_MAX   )
#define PARAM_VOLUME_RWR        INT_DATA ( VOLUME_RWR       , VOL_MAX   )
#define PARAM_VOLUME_COCKPIT    INT_DATA ( VOLUME_COCKPIT   , VOL_MAX   )
#define PARAM_VOLUME_COMMS      INT_DATA ( VOLUME_COMMS     , VOL_MAX   )
#define PARAM_VOLUME_FLIGHT     INT_DATA ( VOLUME_FLIGHT    , VOL_MAX   )
#define PARAM_VOLUME_SOUNDFX    INT_DATA ( VOLUME_SOUNDFX   , VOL_MAX   )

// --- SOUNDFX ---

#define PARAM_SFX_RWR_MIG21     STR_DATA ( SFX_RWR_MIG21    , FIL_RWR_MIG21 )
#define PARAM_SFX_LIST          STR_DATA ( SFX_LIST         , FIL_SFX_LIST  )

#endif // PARAMS_H
