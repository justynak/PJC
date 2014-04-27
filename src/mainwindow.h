#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gamearea.h"
#include <kscreensaver.h>


class MainWindow : public KScreenSaver
{

public:
    MainWindow(WId drawable);
    ~MainWindow();

private:
    GameArea* game;


};

#endif // MAINWINDOW_H
