#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H


#include <kscreensaver.h>
#include <kdialog.h>
#include "gamescreensaver.h"
#include "gamesetup.h"

class GameInterface : public KScreenSaverInterface
{
public:

    KAboutData* s_aboutData;

    virtual KAboutData* aboutData()
    {
        return s_aboutData;
    }

    // function to create screen saver object
    virtual KScreenSaver* create(WId id)
    {
        return new GameScreenSaver(id);
    }

    // function to create setup dialog for screen saver
    virtual QDialog* setup()
    {
        return new GameSetup();
    }

};

#endif // GAMEINTERFACE_H
