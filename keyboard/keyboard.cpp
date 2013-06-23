#include "__svc_keyboard.h"

static xfalcon::services::__svc_keyboard *_keyboard = NULL;

xfalcon::services::__svc_keyboard &keyboard()
{
    _keyboard = (xfalcon::services::__svc_keyboard*)(xfalcon::services::__svc_keyboard::getInstance());
    return *_keyboard;
}
