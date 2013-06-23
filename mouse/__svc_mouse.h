#ifndef __SVC_MOUSE_H
#define __SVC_MOUSE_H

#include "tools/unity_engine.h"
#include "bus/busclient.h"

namespace xfalcon
{
namespace services
{
class __svc_mouse : NEW__USERVICE__<__svc_mouse>,
        private BusClient

{
    SET__USERVICE__<__svc_mouse>;

private:
    __svc_mouse();

    void process(Frame* frame);

public:
    virtual ~__svc_mouse();
    //RETURN_CODE init();
    //RETURN_CODE start();
    //RETURN_CODE stop();
};
}
}

#endif // __SVC_MOUSE_H
