#include "tty_windowtitle.h"
#include <string>

namespace unity
{
namespace tools
{
namespace tty
{
tty_windowTitle::tty_windowTitle(QWidget *target)
    : tty_(target, target->objectName().toStdString())
{
}

void tty_windowTitle::write(const std::string &msg)
{
    _target->setWindowTitle(QString::fromStdString(msg));
}
}
}
}
