#include "qsfmlcanvas.h"

namespace xfalcon
{
namespace services
{
namespace utils
{
QSFMLCanvas::QSFMLCanvas(QWidget *parent, const QPoint &position, const QSize &size)
    : QWidget(parent),
      _initialized(false)
{
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);

    setFocusPolicy(Qt::StrongFocus);

    move(position);
    resize(size);
}

QSFMLCanvas::~QSFMLCanvas()
{
}

void QSFMLCanvas::showEvent(QShowEvent *event)
{
    if (!_initialized)
    {
        sf::Window::create(winId());
        init();
        _initialized = true;
    }
}

QPaintEngine *QSFMLCanvas::paintEngine() const
{
    return 0;
}

void QSFMLCanvas::paintEvent(QPaintEvent *event)
{
    update();
    display();
}
}
}
}

