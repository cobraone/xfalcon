#ifndef XFWND_H
#define XFWND_H

#include <QMainWindow>
#include "ui_xfwnd.h"
#include "tools/interfaces/traceable.h"

namespace ui
{
class xfwnd : public QMainWindow, public unity::tools::interfaces::Traceable
{
    Q_OBJECT

public:
    xfwnd(QWidget *parent = 0);
    ~xfwnd();

private slots:
    void OnClick_PB_SETUP();
    void OnClick_TB_DEBUG();

public:
    Ui::xfwnd ui;
};
}

#endif
