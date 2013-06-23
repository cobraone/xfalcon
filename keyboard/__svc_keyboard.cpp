#include "__svc_keyboard.h"
#include "../tools/unity_engine.h"
#include <SFML/Window.hpp>

namespace xfalcon
{
    namespace services
    {
        __svc_keyboard::__svc_keyboard(): __USERVICE__("__svc_keyboard", M__VOLATILE)
        {
            setControls(NONE);
            listen(CHANNEL_0);
        }

        __svc_keyboard::~__svc_keyboard()
        {
        }

        void __svc_keyboard::process(Frame* frame)
        {
            //sf::Event::KeyEvent* _key = getData<sf::Event::KeyEvent>(frame);

            //console() << ".";

            //delete frame;
        }
    }
}