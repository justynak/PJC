#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include <kscreensaver.h>
#include <kdialog.h>
#include "gamescreensaver.h"
#include "gamesetup.h"


#define VERSION "0.1"
class GameInterface : public KScreenSaverInterface
{
public:

    KAboutData* s_aboutData;

    virtual KAboutData* aboutData()
    {
        s_aboutData = new KAboutData("GameOfLife", 0,
                    ki18n("GameOfLife"), VERSION,
                    ki18n("KDE GameOfLife screensaver."),
                    KAboutData::License_GPL,
                    ki18n("JK"),
                    KLocalizedString(),
                    "http://github.com/justynak",
                    "justyna.kaplinska@gmail.com");
        return s_aboutData;
    }

    // function to create screen saver object
    virtual KScreenSaver* create(WId id)
    {
        s_aboutData = new KAboutData("GameOfLife", 0,
                    ki18n("GameOfLife"), VERSION,
                    ki18n("KDE GameOfLife screensaver."),
                    KAboutData::License_GPL,
                    ki18n("JK"),
                    KLocalizedString(),
                    "http://github.com/justynak",
                    "justyna.kaplinska@gmail.com");
        return new GameScreenSaver(id);
    }

    // function to create setup dialog for screen saver
    virtual QDialog* setup()
    {

        s_aboutData = new KAboutData("GameOfLife", 0,
                    ki18n("GameOfLife"), VERSION,
                    ki18n("KDE GameOfLife screensaver."),
                    KAboutData::License_GPL,
                    ki18n("JK"),
                    KLocalizedString(),
                    "http://github.com/justynak",
                    "justyna.kaplinska@gmail.com");
        return new GameSetup();
    }

};

#endif // GAMEINTERFACE_H
