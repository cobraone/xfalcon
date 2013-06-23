#ifndef __SVC_XFALCON_H
#define __SVC_XFALCON_H

#include "tools/unity_engine.h"
#include "ui/xfwnd.h"
#include "ui/xfalcon_out.h"
#include "bus/busclient.h"

namespace xfalcon
{
namespace services
{
class __svc_xfalcon: NEW__USERVICE__<__svc_xfalcon>,
        protected BusClient
{
    SET__USERVICE__<__svc_xfalcon>;

private:
    ui::xfwnd *__xfwnd;
    xfalcon_out *__xfwnd_out;

    __svc_xfalcon();
    ~__svc_xfalcon();


    void __TEST__();
    void process(Frame data);
public:
    RETURN_CODE init();
    RETURN_CODE start();
    RETURN_CODE pause();
    RETURN_CODE stop();

    QMainWindow *getXfalconWnd();
    QMainWindow *getXfalconOut();
};
}
}

#endif // __SVC_XFALCON_H
