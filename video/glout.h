#ifndef GLOUT_H
#define GLOUT_H

#include <QWidget>
#include "tools/timer/timerloop.h"
#include "tools/unity_engine.h"
#include "tools/tty/tty_windowtitle.h"
//#include <QtOpenGL\qgl.h>
#include "qsfmlcanvas.h"
#include <SFML/System.hpp>
#include "../bus/busclient.h"
#include "../bus/busdefine.h"

using namespace unity::tools;

namespace xfalcon
{
namespace services
{
namespace utils
{
class GLout: public QSFMLCanvas
{
private:
    class __GLLoop: public unity::tools::timer::TimerLoop
    {
    private:
        GLout *_gl_out;
        unsigned int _last_time;
        unsigned long long int _last_loop;
        unsigned long long int _curr_loop;

        class __BusClient: public xfalcon::services::BusClient
        {
        public:
            __BusClient()
            {
                listen(CHANNEL_0);
            }
        } _busclient;

        void exec();
        void __parseEvent(const sf::Event &e);

    public:
        __GLLoop(GLout *host);

        unsigned int getFps();
    } *_gl_loop;

    class __FpsWatcher: public unity::tools::timer::TimerLoop
    {
    private:
        __GLLoop *_loop;
        unity::tools::tty::tty_windowTitle *_out;

        void exec()
        {
            std::string _fps;
            std::stringstream _str;
            _str << _loop->getFps();
            _fps = _str.str();

            _out->write("framerate: " + _fps + "fps");
        }

    public:
        __FpsWatcher(unity::tools::tty::tty_windowTitle *out, __GLLoop *loop)
        {
            this->setSpeed_int(1000);
            this->_loop = loop;
            this->_out = out;
        }
    } *_fps_watcher;

public:
    GLout(QWidget *parent, const QPoint &position, const QSize &size);
    ~GLout();

    void resize(uint w, uint h);

private:
    void init();
    void update();
};
}
}
}

#endif // GLOUT_H
