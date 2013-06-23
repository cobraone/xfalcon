#ifndef XFWND_SETUP_H
#define XFWND_SETUP_H

#include <QDialog>
#include "ui_xfwnd_setup.h"
#include "tools/interfaces/traceable.h"

namespace ui
{
class xfwnd_setup : public QDialog, public unity::tools::interfaces::Traceable
{
    Q_OBJECT

public:
    xfwnd_setup(QWidget *parent = 0);
    ~xfwnd_setup();

private:
    Ui::xfwnd_setup ui;

private slots:
    void onRelease_HS_MASTER(int);
    void onRelease_HS_MUSIC(int);
    void onRelease_HS_ENGINEOUT(int);
    void onRelease_HS_SIDEWINDER(int);
    void onRelease_HS_RWR(int);
    void onRelease_HS_COCKPIT(int);
    void onRelease_HS_OTHERCOMMS(int);
    void onRelease_HS_FLIGHTCOMMS(int);
    void onRelease_HS_SOUNDEFFECTS(int);

};
}

#endif
