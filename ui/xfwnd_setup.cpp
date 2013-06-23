#include "xfwnd_setup.h"
#include "tools/console.h"
#include "../audio/volume.h"

namespace ui
{
xfwnd_setup::xfwnd_setup(QWidget *parent): QDialog(parent), Traceable("xfwnd_setup")
{
    ui.setupUi(this);
    this->setFixedSize(this->size());

    ui.hs_Music->setValue(volume.getVolume_Music());
    ui.hs_Master->setValue(volume.getVolume_Master());
    ui.hs_EngineOut->setValue(volume.getVolume_Channel(CHANNEL_ENGINE));
    ui.hs_Sidewinder->setValue(volume.getVolume_Channel(CHANNEL_SIDEWINDER));
    ui.hs_RWR->setValue(volume.getVolume_Channel(CHANNEL_RWR));
    ui.hs_Cockpit->setValue(volume.getVolume_Channel(CHANNEL_COCKPIT));
    ui.hs_OtherComms->setValue(volume.getVolume_Channel(CHANNEL_COMMS));
    ui.hs_FlightComms->setValue(volume.getVolume_Channel(CHANNEL_FLIGHT));
    ui.hs_SoundEffects->setValue(volume.getVolume_Channel(CHANNEL_SOUNDFX));

    connect(ui.hs_Master,SIGNAL(valueChanged(int)),this,SLOT(onRelease_HS_MASTER(int)));
    connect(ui.hs_Music, SIGNAL(valueChanged(int)), this, SLOT(onRelease_HS_MUSIC(int)));
    connect(ui.hs_EngineOut, SIGNAL(valueChanged(int)), this, SLOT(onRelease_HS_ENGINEOUT(int)));
    connect(ui.hs_Sidewinder, SIGNAL(valueChanged(int)), this, SLOT(onRelease_HS_SIDEWINDER(int)));
    connect(ui.hs_RWR, SIGNAL(valueChanged(int)), this, SLOT(onRelease_HS_RWR(int)));
    connect(ui.hs_Cockpit, SIGNAL(valueChanged(int)), this, SLOT(onRelease_HS_COCKPIT(int)));
    connect(ui.hs_OtherComms, SIGNAL(valueChanged(int)), this, SLOT(onRelease_HS_OTHERCOMMS(int)));
    connect(ui.hs_FlightComms, SIGNAL(valueChanged(int)), this, SLOT(onRelease_HS_FLIGHTCOMMS(int)));
    connect(ui.hs_SoundEffects, SIGNAL(valueChanged(int)), this, SLOT(onRelease_HS_SOUNDEFFECTS(int)));
}

xfwnd_setup::~xfwnd_setup()
{
}

void xfwnd_setup::onRelease_HS_MASTER(int value)
{
    volume.setVolume_Master(value);
}

void xfwnd_setup::onRelease_HS_MUSIC(int value)
{
    volume.setVolume_Music(value);
}

void xfwnd_setup::onRelease_HS_ENGINEOUT(int value)
{
    volume.setVolume_Channel(CHANNEL_ENGINE, value);
}

void xfwnd_setup::onRelease_HS_SIDEWINDER(int value)
{
    volume.setVolume_Channel(CHANNEL_SIDEWINDER, value);
}

void xfwnd_setup::onRelease_HS_RWR(int value)
{
    volume.setVolume_Channel(CHANNEL_RWR, value);
}

void xfwnd_setup::onRelease_HS_COCKPIT(int value)
{
    volume.setVolume_Channel(CHANNEL_COCKPIT, value);
}

void xfwnd_setup::onRelease_HS_OTHERCOMMS(int value)
{
    volume.setVolume_Channel(CHANNEL_COMMS, value);
}

void xfwnd_setup::onRelease_HS_FLIGHTCOMMS(int value)
{
    volume.setVolume_Channel(CHANNEL_FLIGHT, value);
}

void xfwnd_setup::onRelease_HS_SOUNDEFFECTS(int value)
{
    volume.setVolume_Channel(CHANNEL_SOUNDFX, value);
}
}
