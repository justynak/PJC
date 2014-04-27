#ifndef GAMESCREENSAVER_H
#define GAMESCREENSAVER_H

#include "gamearea.h"
#include <kscreensaver.h>


class GameScreenSaver : public KScreenSaver
{

public:
    GameScreenSaver(WId drawable);
    virtual ~GameScreenSaver();

private:
    GameArea* game;
};

#endif // GAMESCREENSAVER_H
