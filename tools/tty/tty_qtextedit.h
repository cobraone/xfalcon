#ifndef TTY_QTEXTEDIT_H
#define TTY_QTEXTEDIT_H

#include "tools/console/__console.h"
#include <QTextEdit>
#include <string>

namespace unity
{
namespace tools
{
namespace tty
{
class tty_QTextEdit : public tty_<QTextEdit>
{
private:
    QTextCursor _cursor;

public:
    tty_QTextEdit(QTextEdit *target);

    void write(const std::string &msg);
};
}
}
}

#endif // TTY_QTEXTEDIT_H
