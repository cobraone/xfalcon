#include "__svc_video.h"
#include "config/config.h"
#include "ui/xfalcon_out.h"
#include "xfalcon.h"
#include "graphics/graphics.h"
#include "../mouse/mouse.h"
#include "../keyboard/keyboard.h"

namespace xfalcon
{
namespace services
{
__svc_video::__svc_video(): __USERVICE__("__svc_video", M__VOLATILE)
{
    __video = NULL;
    setControls(INIT|START);
    dependsOn(&graphics);
    dependsOn(&keyboard);
    dependsOn(&mouse);
}

__svc_video::~__svc_video()
{
}

RETURN_CODE __svc_video::init()
{
    if(INIT__USERVICE__)
    {
        return RC_SUCCESS;
    }

    return RC_FAILURE;
}

RETURN_CODE __svc_video::start()
{
    if (START__USERVICE__)
    {
        //__video = new utils::GLout(xfmain.getXfalconOut());
        __video = new utils::GLout(xfmain.getXfalconOut(), QPoint(0, 0), QSize(640, 480));

        xfmain.getXfalconOut()->setCentralWidget(__video);
        xfmain.getXfalconOut()->show();

        return RC_SUCCESS;
    }

    return RC_FAILURE;
}

RETURN_CODE __svc_video::pause()
{
    return PAUSE__USERVICE__;
}

RETURN_CODE __svc_video::stop()
{
    if (STOP__USERVICE__)
    {
        delete __video;
        xfmain.getXfalconOut()->close();
        return RC_SUCCESS;
    }

    return RC_FAILURE;
}
}
}
