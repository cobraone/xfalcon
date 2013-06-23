#include "__svc_mouse.h"
#include "../tools/unity_engine.h"
#include <SFML/Window.hpp>

namespace xfalcon
{
    namespace services
    {
        __svc_mouse::__svc_mouse(): __USERVICE__("__svc_mouse", M__VOLATILE)
        {
            setControls(NONE);
            listen(CHANNEL_1);
        }

        __svc_mouse::~__svc_mouse()
        {
        }

        void __svc_mouse::process(Frame* frame)
        {
            //console() << ":";
        }
    }
}