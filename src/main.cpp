#include <QtGui/QApplication>
#include "gameinterface.h"
#include <QDebug>
#include "gameinterface.h"

int main(int argc, char*argv[])
{
    /*
    s_aboutData = new KAboutData("gameoflife", 0,
                ki18n("GameOfLife"), 0.1,
                ki18n("KDE GameOfLife screensaver"),
                KAboutData::License_GPL,
                ki18n("Copyright (C) 2014 Justyna K"),
                KLocalizedString(),
                "http://github.com/justynak/PJC",
                "justyna.kaplinska@gmail.com");

    s_aboutData->addAuthor(ki18n("Justyna K"),
                ki18n("Enjoy!"),
                "justyna.kaplinska@gmail.com");
*/
    GameInterface kss;
    return kScreenSaverMain(argc, argv, kss);
}

