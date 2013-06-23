#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "__svc_keyboard.h"

xfalcon::services::__svc_keyboard &keyboard();

#define keyboard keyboard()

#endif // KEYBOARD_H
