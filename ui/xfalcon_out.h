#ifndef XFALCON_OUT_H
#define XFALCON_OUT_H

#include <QMainWindow>

namespace Ui {
class xfalcon_out;
}

class xfalcon_out : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit xfalcon_out(QWidget *parent = 0);
    ~xfalcon_out();

protected:
    void closeEvent(QCloseEvent *event);
    
private:
    Ui::xfalcon_out *ui;
};

#endif // XFALCON_OUT_H
