#ifndef XFALCON_MFD_H
#define XFALCON_MFD_H

#include <QWidget>

namespace Ui {
class xfalcon_MFD;
}

class xfalcon_MFD : public QWidget
{
    Q_OBJECT
    
public:
    explicit xfalcon_MFD(QWidget *parent = 0);
    ~xfalcon_MFD();
    
private:
    Ui::xfalcon_MFD *ui;
};

#endif // XFALCON_MFD_H
