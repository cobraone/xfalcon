#include "tty_qtextedit.h"
#include <string>
#include <QStringList>

namespace unity
{
namespace tools
{
namespace tty
{
tty_QTextEdit::tty_QTextEdit(QTextEdit *target)
    : tty_(target, target->objectName().toStdString())
{
}

void tty_QTextEdit::write(const std::string &msg)
{
    _target->insertPlainText(QString::fromStdString(msg));
    _cursor = _target->textCursor();
    _cursor.movePosition(QTextCursor::End);
    _target->setTextCursor(_cursor);
}
}
}
}

