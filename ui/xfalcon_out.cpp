#include "xfalcon_out.h"
#include "ui_xfalcon_out.h"
#include "../video/video.h"

xfalcon_out::xfalcon_out(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::xfalcon_out)
{
    ui->setupUi(this);
}

xfalcon_out::~xfalcon_out()
{
    delete ui;
}

void xfalcon_out::closeEvent(QCloseEvent *event)
{
    video.stop();
}
