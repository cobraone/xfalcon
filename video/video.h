#ifndef VIDEO_H
#define VIDEO_H

#include "__svc_video.h"

xfalcon::services::__svc_video &video();

#define video video()

#endif // VIDEO_H
