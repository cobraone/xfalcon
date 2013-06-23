#include "xfalcon_mfd.h"
#include "ui_xfalcon_mfd.h"

xfalcon_MFD::xfalcon_MFD(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::xfalcon_MFD)
{
    ui->setupUi(this);
}

xfalcon_MFD::~xfalcon_MFD()
{
    delete ui;
}
