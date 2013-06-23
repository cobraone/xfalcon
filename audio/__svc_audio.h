#ifndef __SVC_AUDIO_H
#define __SVC_AUDIO_H

#include "tools/unity_engine.h"

namespace xfalcon
{
namespace services
{
class __svc_audio : NEW__USERVICE__<__svc_audio>
{
    SET__USERVICE__<__svc_audio>;

private:
    __svc_audio();

public:
    virtual ~__svc_audio();
    RETURN_CODE init();
};
}
}

#endif // __SVC_AUDIO_H
