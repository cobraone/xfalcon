#include "__svc_time.h"

namespace xfalcon
{
namespace services
{
__svc_time::__svc_time(): __USERVICE__("__svc_time", M__VOLATILE)
{
}

uint __svc_time::getTime()
{
    return _timer._time;
}

__svc_time::__timer::__timer()
{
    _time = 1;
    this->setSpeed_int(1000);
    this->start();
}

void __svc_time::__timer::exec()
{
    _time++;
}
}
}
