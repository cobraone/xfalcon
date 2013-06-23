#ifndef MOUSE_H
#define MOUSe_H

#include "__svc_mouse.h"

xfalcon::services::__svc_mouse &mouse();

#define mouse mouse()

#endif // MOUSE_H
