#ifndef XFWND_DEBUG_H
#define XFWND_DEBUG_H

#include <QDialog>
#include "tools/interfaces/traceable.h"
#include "ui_xfwnd_debug.h"

namespace ui
{
class xfwnd_debug : public QDialog,
        public unity::tools::interfaces::Traceable
{
    Q_OBJECT
    
public:
    explicit xfwnd_debug(QWidget *parent = 0);
    ~xfwnd_debug();
    
private:
    //xfalcon::services::BusClient *_bc;
    Ui::xfwnd_debug ui;

private slots:
    void OnClick_PB_KILLALL();
    void OnClick_PB_SNDSTART();
    void OnClick_PB_ULIST();
    void OnClick_PB_INITCFG();
    void OnClick_PB_INITVIDEO();
    void on_pb_BusStats_clicked();
    void on_pb_Broadcast_clicked();
};
}

#endif // XFWND_DEBUG_H
