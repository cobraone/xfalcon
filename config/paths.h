#ifndef PATHS_H
#define PATHS_H

#include "tools/unity_engine.h"

#define PATH_DATA       __CLLINE__<std::string, std::string>

#define CONFIG          "DIR__CONFIG"
#define SOUNDFX         "DIR__SOUNDFX"
#define MUSIC           "DIR__MUSIC"
#define OBJECTS         "DIR__OBJECTS"

#define DIR__CONFIG     PATH_DATA ( CONFIG      , "./"            )
#define DIR__SOUNDFX    PATH_DATA ( SOUNDFX     , "C:/sfx/"       )
#define DIR__MUSIC      PATH_DATA ( MUSIC       , "C:/music/"     )
#define DIR__OBJECTS    PATH_DATA ( OBJECTS     , "./objects/"    )

#define FIL__XFCONFIG   "xfalcon.cfg"

#endif // PATHS_H
