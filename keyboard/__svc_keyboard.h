#ifndef __SVC_KEYBOARD_H
#define __SVC_KEYBOARD_H

#include "tools/unity_engine.h"
#include "bus/busclient.h"

namespace xfalcon
{
namespace services
{
class __svc_keyboard : NEW__USERVICE__<__svc_keyboard>,
        private BusClient

{
    SET__USERVICE__<__svc_keyboard>;

private:
    __svc_keyboard();

    void process(Frame* frame);

public:
    virtual ~__svc_keyboard();
    //RETURN_CODE init();
    //RETURN_CODE start();
    //RETURN_CODE stop();
};
}
}

#endif // __SVC_KEYBOARD_H
