#include "glout.h"
#include <QtOpenGL/qgl.h>
#include <gl\GLU.h>
#include "tools/unity_engine.h"
#include "graphics/graphics.h"
#include "tools/tty/tty_windowtitle.h"
#include "../time/time.h"

namespace xfalcon
{
namespace services
{
namespace utils
{
GLout::GLout(QWidget *parent, const QPoint &position, const QSize &size):
QSFMLCanvas(parent, position, size)
{
    unity::tools::tty::tty_windowTitle *_out = new unity::tools::tty::tty_windowTitle(parent);
    _gl_loop = new __GLLoop(this);
    _fps_watcher = new __FpsWatcher(_out, _gl_loop);
    _gl_loop->setSpeed_int(1); // TODO prendre en compte la fréquence du bus

    _fps_watcher->start();
}

GLout::~GLout()
{
    delete _gl_loop;
    delete _fps_watcher;
}

void GLout::init()
{
    glShadeModel(GL_SMOOTH);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glEnable(GL_LIGHTING);	// Active l'éclairage
    glEnable(GL_LIGHT0);	// Allume la lumière n°1

    resize(this->size().width(), this->size().height());

    _gl_loop->start();
}

int i = 0;

void GLout::update()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

	glTranslatef(0.0f,0.0f,-10.0f);
    glRotatef(90.0f,0.0f,0.0f,1.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

    glRotatef(i++, 0.0f, 0.0f, 1.0f);

    graphics.drawAll();
}

void GLout::resize(uint w, uint h)
{
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLdouble)w/(GLdouble)h,0.1f,100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

GLout::__GLLoop::__GLLoop(GLout *host)
{
    _gl_out = host;
    _last_loop = 0;
    _curr_loop = 1;
    _last_time = 0;
}

void GLout::__GLLoop::exec()
{
    //_gl_out->update();
    sf::Event e;

    while(_gl_out->pollEvent(e))
        if (e.type == sf::Event::Closed)
            this->stop();
        else
            if (e.type == sf::Event::Resized)
                _gl_out->resize(e.size.width, e.size.height);
            else
                __parseEvent(e);

    _gl_out->repaint();
    _curr_loop++;
}

void GLout::__GLLoop::__parseEvent(const sf::Event &e)
{
    //busMutex.lock();

    if (e.type == sf::Event::KeyPressed)
        _busclient.broadcast<sf::Event::KeyEvent>(CHANNEL_0, TYPE_EVENT_KEYPRESSED, e.key, PRIORITY_HIGH);

    if (e.type == sf::Event::MouseMoved)
        _busclient.broadcast<sf::Event::MouseMoveEvent>(CHANNEL_1, TYPE_EVENT_MOUSEMOVED, e.mouseMove);

    //busMutex.unlock();
}

unsigned int GLout::__GLLoop::getFps()
{
    unsigned int _fps = 0;
    unsigned int _curr_time = time.getTime();

    if (_curr_time > _last_time)
    {
        _fps = (_curr_loop - _last_loop) / (_curr_time - _last_time);
        _last_loop = _curr_loop;
        _last_time = _curr_time;
    }

    return _fps;
}
}
}
}
