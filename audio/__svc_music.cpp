#include "__svc_music.h"
#include "tools/console.h"
#include "tools/exceptions.h"
#include "audio.h"
#include <fstream>
#include "../config/config.h"
#include "volume.h"

namespace xfalcon
{
namespace services
{
__svc_music::__svc_music(): __uservice("__svc_music", M__VOLATILE)
{
    setControls(INIT|START);
    dependsOn(&audio);
    dependsOn(&config);
    dependsOn(&volume);
}

__svc_music::~__svc_music()
{
    //Mix_FreeMusic(__music);
}

RETURN_CODE __svc_music::init()
{
    if (INIT__USERVICE__)
    {
        //config.init();
        //console() << config.music[MUSIC_SOURCE];
        __loadPlayList(config.paths[MUSIC] + config.music[MUSIC_SOURCE] + ".playlist.txt");
        return RC_SUCCESS;
    }

    return RC_FAILURE;
}

RETURN_CODE __svc_music::start()
{
    if (START__USERVICE__)
    {
        //__music = __plist.getData("C:/music/ui2.wav");
        //Mix_PlayMusic(__music, 1);

        //if (Mix_PlayingMusic())
        //    console() << "playing\n";
        Mix_PlayMusic(__plist.getFirst(), 1);
        TimerLoop::setSpeed_int(1000);
        TimerLoop::start();

        return RC_SUCCESS;
    }

    return RC_FAILURE;
}

void __svc_music::__loadMusic(const std::string &filename)
{
    console() << MSG__TAB4 << MSG__LOAD << "\"" << filename << "\"... ";


    if (!__plist.exist(filename))
    {
        Mix_Music *__music = Mix_LoadMUS(filename.c_str());

        if (__music)
        {
            PlayLine __pline;
            __pline.lname = filename;
            __pline.ldata = __music;
            __plist.add(__pline);

            console() << MSG__OK;
        }
        else
            fatal(E__FILE_NOT_FOUND);
    }
    else
        warning(W__ALREADY_LOADED);
}

void __svc_music::__loadPlayList(const string &filename)
{
    ifstream __file(filename);

    console() << MSG__LOAD << "playlist \"" << filename << "\"... ";

    if (__file)
    {
        console() << MSG__OK;
        string __line;

        while(getline(__file, __line))
            __loadMusic(__line);
    }
    else
        error(E__FILE_NOT_FOUND);

/*    Mix_Music *__music = Mix_LoadMUS("c:/music/ui1.ogg");
    if (!__music)
        qDebug() << "bouh";
    Mix_PlayMusic(__music, 1);*/
}

void __svc_music::exec()
{
    //Mix_PlayMusic(__music, 1);
    //while(Mix_PlayingMusic());

    // bad design
    // exec shouble check every ???ms wether playing music or not, and then if not, start playing a new file

    if (!Mix_PlayingMusic())
        Mix_PlayMusic(__plist.getNext(), 1);
}
}
}
