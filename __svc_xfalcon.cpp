#include "__svc_xfalcon.h"
#include "tools/console.h"
#include "sim/sim.h"
#include <QtGlobal>
#include <SDL_version.h>
#include <SDL_mixer.h>
#include "tools/version.h"
#include "bus/bus.h"
#include "keyboard/keyboard.h"

namespace xfalcon
{
namespace services
{
__svc_xfalcon::__svc_xfalcon(): __uservice("__svc_xfalcon", M__PERSISTENT)
{
    console() << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    console() << "                             <<<  xfalcon  >>>\n";
    console() << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    console() << "Qt:" << qVersion() << "\n";

    console() << "SDL:" << SDL_MAJOR_VERSION
              << "." << SDL_MINOR_VERSION
              << "." << SDL_PATCHLEVEL << "\n";

    console() << "SDL_MIXER:" << SDL_MIXER_MAJOR_VERSION
              << "." << SDL_MIXER_MINOR_VERSION
              << "." << SDL_MIXER_PATCHLEVEL << "\n";

    console() << "SFML: 2.0\n";

    console() << "unity: " << UNITY_MAJOR_VERSION
              << "." << UNITY_MINOR_VERSION
              << "." << UNITY_PATCHLEVEL << "\n";

    setControls(INIT);
    setControls(START);

    console() << "\n__TEST_BEGIN__\n";
    __TEST__();
    console() << "__TEST_END__\n\n";
}

__svc_xfalcon::~__svc_xfalcon()
{
    this->stop();
}

RETURN_CODE __svc_xfalcon::start()
{
    if (START__USERVICE__)
    {
        __xfwnd->show();
        //sim.init();

        return RC_SUCCESS;
    }

    return RC_FAILURE;
}

RETURN_CODE __svc_xfalcon::stop()
{
    if (STOP__USERVICE__)
    {
        delete __xfwnd_out;
        delete __xfwnd;

        return RC_SUCCESS;
    }

    return RC_FAILURE;
}

RETURN_CODE __svc_xfalcon::pause()
{
    warning("__svc_xfalcon::pause()", W__IGNORED);
    return RC_FAILURE;
}

RETURN_CODE __svc_xfalcon::init()
{
    if (INIT__USERVICE__)
    {
        __xfwnd = new ui::xfwnd();
        __xfwnd_out = new xfalcon_out(__xfwnd);

        return RC_SUCCESS;
    }

    return RC_FAILURE;
}

QMainWindow *__svc_xfalcon::getXfalconWnd()
{
    return __xfwnd;
}

QMainWindow *__svc_xfalcon::getXfalconOut()
{
    return __xfwnd_out;
}

void __svc_xfalcon::__TEST__()
{
}
}
}
