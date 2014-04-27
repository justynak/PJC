#include "gamesetup.h"
#include "ui_gamesetup.h"

GameSetup::GameSetup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameSetup)
{
    ui->setupUi(this);
}

GameSetup::~GameSetup()
{
    delete ui;
}
