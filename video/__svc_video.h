#ifndef __SVC_VIDEO_H
#define __SVC_VIDEO_H

#include "tools/unity_engine.h"
#include "glout.h"
#include <QMainWindow>

namespace xfalcon
{
namespace services
{
class Mesh;

class __svc_video: NEW__USERVICE__<__svc_video>
{
    SET__USERVICE__<__svc_video>;

private:
    utils::GLout *__video;

    __svc_video();
    ~__svc_video();

public:
    RETURN_CODE init();
    RETURN_CODE start();
    RETURN_CODE pause();
    RETURN_CODE stop();

    //RETURN_CODE draw(Mesh *mesh);
    RETURN_CODE enableFpsWatch();
    RETURN_CODE disableFpsWatch();
};
}
}

#endif // __SVC_VIDEO_H
