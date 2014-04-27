#include "mainwindow.h"
#include <QDebug>
#include <QPalette>


MainWindow::MainWindow(WId id) : KScreenSaver(id)
{

    QPalette p = QPalette();
    p.setColor(QWidget::backgroundRole(), Qt::black);
    setPalette(p);

    game = new GameArea();
    embed(game);

    game->show();

}

MainWindow::~MainWindow()
{
    delete game;
}



