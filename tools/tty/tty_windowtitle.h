#ifndef TTY_WINDOWTITLE_H
#define TTY_WINDOWTITLE_H

#include <QWidget>
#include "../console/__console.h"

namespace unity
{
namespace tools
{
namespace tty
{
class tty_windowTitle : public tty_<QWidget>
{
public:
    tty_windowTitle(QWidget *target);

    void write(const std::string &msg);
};
}
}
}

#endif // TTY_WINDOWTITLE_H
