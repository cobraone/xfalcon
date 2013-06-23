#include "__svc_sim.h"

#include "config/config.h"
#include "audio/audio.h"
#include "video/video.h"

namespace xfalcon
{
namespace services
{
__svc_sim::__svc_sim(): __uservice("__svc_sim", M__VOLATILE)
{
    setControls(ALL);

    dependsOn(&config);
    dependsOn(&video);
    dependsOn(&audio);
}

__svc_sim::~__svc_sim()
{
}

RETURN_CODE __svc_sim::init()
{
    if (INIT__USERVICE__)
    {
        //__sim_loop = utils::SimLoop::getInstance();
        //__sim_loop->init();
        //__sim_loop.repeat(500);
        __sim_loop.setSpeed_int(10);
        __sim_loop.start();

        return RC_SUCCESS;
    }

    return RC_FAILURE;
}

RETURN_CODE __svc_sim::start()
{
    if (START__USERVICE__)
    {
        //__sim_loop->start();
        return RC_SUCCESS;
    }

    return RC_FAILURE;
}

RETURN_CODE __svc_sim::pause()
{
    warning("__svc_sim::pause()", W__IGNORED);
    return RC_FAILURE;
}

RETURN_CODE __svc_sim::stop()
{
    if (STOP__USERVICE__)
    {
        __sim_loop.stop();

        return RC_SUCCESS;
    }

    return RC_FAILURE;
}
}
}
