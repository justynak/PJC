#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "area.h"
#include <kscreensaver.h>


class MainWindow : public KScreenSaver
{

public:
    MainWindow(WId drawable);
    ~MainWindow();

private:
    Area* game;


};

#endif // MAINWINDOW_H
