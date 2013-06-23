#ifndef QSFMLCANVAS_H
#define QSFMLCANVAS_H

#include <QWidget>
#include "tools/timer/timerloop.h"
#include "tools/unity_engine.h"
#include "tools/tty/tty_windowtitle.h"
#include <SFML/Graphics.hpp>

using namespace unity::tools;

namespace xfalcon
{
namespace services
{
namespace utils
{
class QSFMLCanvas: public QWidget, public sf::RenderWindow
{
private:
    bool _initialized;

public:
    QSFMLCanvas(QWidget *parent, const QPoint &position, const QSize &size);
    virtual ~QSFMLCanvas();

private:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual QPaintEngine *paintEngine() const;
    virtual void showEvent(QShowEvent *event);
    virtual void paintEvent(QPaintEvent *event);
};

}
}
}

#endif // QSFMLCANVAS_H
