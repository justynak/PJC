#include "gamesetup.h"
#include "ui_gamesetup.h"

GameSetup::GameSetup(QWidget *parent) :
    ui(new Ui::GameSetup)
{
    ui->setupUi(this);

    ui->boxShapes->addItem("Rectangle");
    ui->boxShapes->addItem("Rounded rectangle");
    ui->boxShapes->addItem("Ellipse");

    connect(ui->sliderR, SIGNAL(valueChanged(int)), this, SLOT(on_sliderR_valueChanged(int)));
    connect(ui->sliderG, SIGNAL(valueChanged(int)), this, SLOT(on_sliderG_valueChanged(int)));
    connect(ui->sliderB, SIGNAL(valueChanged(int)), this, SLOT(on_sliderB_valueChanged(int)));

    connect(ui->sliderR_2, SIGNAL(valueChanged(int)), this, SLOT(on_sliderR_2_valueChanged(int)));
    connect(ui->sliderG_2, SIGNAL(valueChanged(int)), this, SLOT(on_sliderG_2_valueChanged(int)));
    connect(ui->sliderB_2, SIGNAL(valueChanged(int)), this, SLOT(on_sliderB_2_valueChanged(int)));

    connect(ui->buttonOk, SIGNAL(clicked()), this, SLOT(on_buttonOk_clicked()));
    connect(ui->buttonExit, SIGNAL(clicked()), this, SLOT(on_buttonExit_clicked()));
    connect(ui->buttonDefault, SIGNAL(clicked()), this, SLOT(on_buttonDefault_clicked()));

    settings = new GameSettings();
}

GameSetup::~GameSetup()
{
    delete ui;
}

void GameSetup::on_sliderR_valueChanged(int )
{
    QColor c = QColor(ui->sliderR->value(),ui->sliderG->value(), ui->sliderB->value());
    cell.fill(c);
    ui->colorLabelCell->setPixmap(cell);
}

void GameSetup::on_sliderG_valueChanged(int )
{
    QColor c = QColor(ui->sliderR->value(),ui->sliderG->value(), ui->sliderB->value());
    cell.fill(c);
    ui->colorLabelCell->setPixmap(cell);
}

void GameSetup::on_sliderB_valueChanged(int )
{
    QColor c = QColor(ui->sliderR->value(),ui->sliderG->value(), ui->sliderB->value());
    cell.fill(c);
    ui->colorLabelCell->setPixmap(cell);
}

void GameSetup::on_sliderR_2_valueChanged(int )
{
    QColor c = QColor(ui->sliderR_2->value(),ui->sliderG_2->value(), ui->sliderB_2->value());
    bkg.fill(c);
    ui->colorLabelBkg->setPixmap(bkg);
}

void GameSetup::on_sliderG_2_valueChanged(int )
{
    QColor c = QColor(ui->sliderR_2->value(),ui->sliderG_2->value(), ui->sliderB_2->value());
    bkg.fill(c);
    ui->colorLabelBkg->setPixmap(bkg);
}

void GameSetup::on_sliderB_2_valueChanged(int )
{
    QColor c = QColor(ui->sliderR_2->value(),ui->sliderG_2->value(), ui->sliderB_2->value());
    bkg.fill(c);
    ui->colorLabelBkg->setPixmap(bkg);
}

void GameSetup::on_buttonDefault_clicked()
{
    settings->RestoreDefault();
}

void GameSetup::on_buttonOk_clicked()
{
    //
    settings->shape = static_cast<Shape>(ui->boxShapes->currentIndex());

    QList<unsigned int> list1;

    if(ui->box0A->isChecked()) list1.append(0);
    if(ui->box1A->isChecked()) list1.append(1);
    if(ui->box2A->isChecked()) list1.append(2);
    if(ui->box3A->isChecked()) list1.append(3);
    if(ui->box4A->isChecked()) list1.append(4);
    if(ui->box5A->isChecked()) list1.append(5);
    if(ui->box6A->isChecked()) list1.append(6);
    if(ui->box7A->isChecked()) list1.append(7);
    if(ui->box8A->isChecked()) list1.append(8);
    if(ui->box9A->isChecked()) list1.append(9);


    settings->nToStayAlive = list1;

    list1.clear();

    if(ui->box0R->isChecked()) list1.append(0);
    if(ui->box1R->isChecked()) list1.append(1);
    if(ui->box2R->isChecked()) list1.append(2);
    if(ui->box3R->isChecked()) list1.append(3);
    if(ui->box4R->isChecked()) list1.append(4);
    if(ui->box5R->isChecked()) list1.append(5);
    if(ui->box6R->isChecked()) list1.append(6);
    if(ui->box7R->isChecked()) list1.append(7);
    if(ui->box8R->isChecked()) list1.append(8);
    if(ui->box9R->isChecked()) list1.append(9);

    settings->nToRevive = list1;

    settings->gameAreaSize = QSize(ui->lineX->text().toInt(), ui->lineY->text().toInt());
    settings->cellColor = QColor(ui->sliderR->value(),ui->sliderG->value(), ui->sliderB->value());
    settings->bkgColor = QColor(ui->sliderR_2->value(),ui->sliderG_2->value(), ui->sliderB_2->value());
    settings->Save();
}

void GameSetup::on_buttonExit_clicked()
{
    //this->destroy();
}
