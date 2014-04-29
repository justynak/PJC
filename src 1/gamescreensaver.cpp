#include "gamescreensaver.h"
#include <QDebug>
#include <QPalette>


GameScreenSaver::GameScreenSaver(WId id) : KScreenSaver(id)
{

    QPalette p = QPalette();
    p.setColor(QWidget::backgroundRole(), Qt::black);
    setPalette(p);

    game = new GameArea();
    embed(game);

    game->show();

}

GameScreenSaver::~GameScreenSaver()
{
    delete game;
}



