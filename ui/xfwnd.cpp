#include "xfwnd.h"
#include "xfwnd_setup.h"
#include "xfwnd_debug.h"
//#include "xfglout.h"
#include "tools/console.h"
#include "tools/tty/tty_qtextedit.h"
#include "audio/audio.h"

namespace ui
{
xfwnd::xfwnd(QWidget *parent) : QMainWindow(parent), Traceable("xfwnd")
{
    ui.setupUi(this);
    this->setCentralWidget(ui.verticalLayoutWidget);

    connect(ui.pb_Setup, SIGNAL(clicked()), this, SLOT(OnClick_PB_SETUP()));
    connect(ui.tb_debug, SIGNAL(clicked()), this, SLOT(OnClick_TB_DEBUG()));

    console() >> new unity::tools::tty::tty_QTextEdit(this->ui.te_MainWindow);

    //sound().start();
}

xfwnd::~xfwnd()
{
}

void xfwnd::OnClick_PB_SETUP()
{
    console() << MSG__CLICK << "PB_SETUP\n";

    xfwnd_setup *w = new xfwnd_setup(this);
    w->show();
}

void xfwnd::OnClick_TB_DEBUG()
{
    console() << MSG__CLICK << "TB_DEBUG\n";

    xfwnd_debug *w = new xfwnd_debug(this);
    w->show();
}
}
