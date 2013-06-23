#ifndef VOLUME_H
#define VOLUME_H

#include "__svc_volume.h"

xfalcon::services::__svc_volume &volume();

#define volume volume()

#endif // VOLUME_H
