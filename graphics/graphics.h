#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "__svc_graphics.h"

xfalcon::services::__svc_graphics &graphics();

#define graphics graphics()

#endif // GRAPHICS_H
