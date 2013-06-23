#include "xfwnd_debug.h"
#include "ui_xfwnd_debug.h"
#include "tools/console.h"
#include "tools/proc.h"
#include "audio/audio.h"
#include "tools/enums.h"
#include "audio/music.h"
#include "config/config.h"
#include "video/video.h"
#include "sim/sim.h"
#include "xfalcon_out.h"
#include "audio/soundfx.h"
#include "bus/bus.h"
#include "sdl/sdlmain.h"

ui::xfwnd_debug::xfwnd_debug(QWidget *parent) :
    QDialog(parent),
    Traceable("xfwnd_debug")
  //ui(new Ui::xfwnd_debug)
{
    ui.setupUi(this);

    connect(ui.pb_KillAll, SIGNAL(clicked()), this, SLOT(OnClick_PB_KILLALL()));
    connect(ui.pb_SndStart,SIGNAL(clicked()), this, SLOT(OnClick_PB_SNDSTART()));
    connect(ui.pb_ulist, SIGNAL(clicked()), this, SLOT(OnClick_PB_ULIST()));
    connect(ui.pb_InitCfg, SIGNAL(pressed()), this, SLOT(OnClick_PB_INITCFG()));
    connect(ui.pb_InitVideo, SIGNAL(clicked()), this, SLOT(OnClick_PB_INITVIDEO()));
}

ui::xfwnd_debug::~xfwnd_debug()
{
}

void ui::xfwnd_debug::OnClick_PB_KILLALL()
{
    console() << MSG__CLICK << "PB_KILLALL\n";
    proc().killAll();
}

void ui::xfwnd_debug::OnClick_PB_SNDSTART()
{
    console() << MSG__CLICK << "PB_SNDSTART\n";
    //audio.start();
    //music().init();
    //SDL().start();
    music.start();
    //soundfx.init();
    //soundfx.play(SFX_RWR_MIG21);
    //config().init();
}

void ui::xfwnd_debug::OnClick_PB_ULIST()
{
    console() << MSG__CLICK << "PB_ULIST\n";
    proc().ulist();
    //bus.stats();
}


void ui::xfwnd_debug::OnClick_PB_INITCFG()
{

    console() << MSG__CLICK << "PB_INITCFG\n";

    //config.init();
    //sim.init();
    //soundfx.play(SFX_RWR_MIG21);
    //sim.start();
    //_debuglisten(CHANNEL_0);

    int a = 1;
    //_debug_busclient.broadcast(1, &a, sizeof(a));
}

void ui::xfwnd_debug::OnClick_PB_INITVIDEO()
{
    console() << MSG__CLICK << "PB_INITVIDEO\n";
    video.init();
    video.start();
}

void ui::xfwnd_debug::on_pb_BusStats_clicked()
{
    bus.stats();
}

void ui::xfwnd_debug::on_pb_Broadcast_clicked()
{
    //_debug_busclient.broadcast(ui.le_ID->text.toInt(), ui.le_Data->text.toInt());
}
