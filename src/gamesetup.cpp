#include "gamesetup.h"
#include "ui_gamesetup.h"

#include <QDesktopWidget>
#include <QWidget>
#include <kaboutapplicationdialog.h>


GameSetup::GameSetup(QWidget *parent) :
    ui(new Ui::GameSetup)
{

    settings = new GameSettings();
    setCaption(i18n("Setup GameOfLife"));
    setButtons(Ok|Cancel|Help|Default);
    setDefaultButton(Ok);
    setModal(true);
    showButtonSeparator(true);
    setButtonText(Help, i18n("A&bout"));

    QWidget *main = new QWidget(this);
    setMainWidget(main);

    ui->setupUi(main);

    ui->boxShapes->addItem("Rectangle");
    ui->boxShapes->addItem("Rounded rectangle");
    ui->boxShapes->addItem("Ellipse");

    cell = QPixmap(71, 21);
    bkg = QPixmap(71, 21);


    connect(ui->sliderR, SIGNAL(valueChanged(int)), this, SLOT(onSliderRValueChanged(int)));
    connect(ui->sliderG, SIGNAL(valueChanged(int)), this, SLOT(onSliderGValueChanged(int)));
    connect(ui->sliderB, SIGNAL(valueChanged(int)), this, SLOT(onSliderValueChanged(int)));

    connect(ui->sliderR_2, SIGNAL(valueChanged(int)), this, SLOT(onSliderR_2ValueChanged(int)));
    connect(ui->sliderG_2, SIGNAL(valueChanged(int)), this, SLOT(onSliderG_2ValueChanged(int)));
    connect(ui->sliderB_2, SIGNAL(valueChanged(int)), this, SLOT(onSliderB_2ValueChanged(int)));


    connect(this, SIGNAL(okClicked()), SLOT(onOkClicked()));
    connect(this, SIGNAL(helpClicked()), SLOT(onHelpClicked()));
    connect(this, SIGNAL(defaultClicked()), SLOT(onDefaultClicked()));

    ShowSettings();
}

GameSetup::~GameSetup()
{
    delete ui;
    if(settings != NULL) delete settings;
}

void GameSetup::onSliderRValueChanged(int )
{
    QColor c = QColor(ui->sliderR->value(),ui->sliderG->value(), ui->sliderB->value());
    cell.fill(c);
    ui->colorLabelCell->setPixmap(cell);
}

void GameSetup::onSliderGValueChanged(int )
{
    QColor c = QColor(ui->sliderR->value(),ui->sliderG->value(), ui->sliderB->value());
    cell.fill(c);
    ui->colorLabelCell->setPixmap(cell);
}

void GameSetup::onSliderBValueChanged(int )
{
    QColor c = QColor(ui->sliderR->value(),ui->sliderG->value(), ui->sliderB->value());
    cell.fill(c);
    ui->colorLabelCell->setPixmap(cell);
}

void GameSetup::onSliderR_2ValueChanged(int )
{
    QColor c = QColor(ui->sliderR_2->value(),ui->sliderG_2->value(), ui->sliderB_2->value());
    bkg.fill(c);
    ui->colorLabelBkg->setPixmap(bkg);
}

void GameSetup::onSliderG_2ValueChanged(int )
{
    QColor c = QColor(ui->sliderR_2->value(),ui->sliderG_2->value(), ui->sliderB_2->value());
    bkg.fill(c);
    ui->colorLabelBkg->setPixmap(bkg);
}

void GameSetup::onSliderB_2ValueChanged(int )
{
    QColor c = QColor(ui->sliderR_2->value(),ui->sliderG_2->value(), ui->sliderB_2->value());
    bkg.fill(c);
    ui->colorLabelBkg->setPixmap(bkg);
}

void GameSetup::onDefaultClicked()
{
    settings->RestoreDefault();
    ShowSettings();
}

void GameSetup::onOkClicked()
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

    ShowSettings();

    accept();
}

void GameSetup::onHelpClicked()
{

}



void GameSetup::ShowSettings()
{
    settings->nToStayAlive.contains(0) ? ui->box0A->setChecked(true) : ui->box0A->setChecked(false);
    settings->nToStayAlive.contains(1) ? ui->box1A->setChecked(true) : ui->box1A->setChecked(false);
    settings->nToStayAlive.contains(2) ? ui->box2A->setChecked(true) : ui->box2A->setChecked(false);
    settings->nToStayAlive.contains(3) ? ui->box3A->setChecked(true) : ui->box3A->setChecked(false);
    settings->nToStayAlive.contains(4) ? ui->box4A->setChecked(true) : ui->box4A->setChecked(false);
    settings->nToStayAlive.contains(5) ? ui->box5A->setChecked(true) : ui->box5A->setChecked(false);
    settings->nToStayAlive.contains(6) ? ui->box6A->setChecked(true) : ui->box6A->setChecked(false);
    settings->nToStayAlive.contains(7) ? ui->box7A->setChecked(true) : ui->box7A->setChecked(false);
    settings->nToStayAlive.contains(8) ? ui->box8A->setChecked(true) : ui->box8A->setChecked(false);
    settings->nToStayAlive.contains(9) ? ui->box9A->setChecked(true) : ui->box9A->setChecked(false);


    settings->nToRevive.contains(0) ? ui->box0R->setChecked(true) : ui->box0R->setChecked(false);
    settings->nToRevive.contains(1) ? ui->box1R->setChecked(true) : ui->box1R->setChecked(false);
    settings->nToRevive.contains(2) ? ui->box2R->setChecked(true) : ui->box2R->setChecked(false);
    settings->nToRevive.contains(3) ? ui->box3R->setChecked(true) : ui->box3R->setChecked(false);
    settings->nToRevive.contains(4) ? ui->box4R->setChecked(true) : ui->box4R->setChecked(false);
    settings->nToRevive.contains(5) ? ui->box5R->setChecked(true) : ui->box5R->setChecked(false);
    settings->nToRevive.contains(6) ? ui->box6R->setChecked(true) : ui->box6R->setChecked(false);
    settings->nToRevive.contains(7) ? ui->box7R->setChecked(true) : ui->box7R->setChecked(false);
    settings->nToRevive.contains(8) ? ui->box8R->setChecked(true) : ui->box8R->setChecked(false);
    settings->nToRevive.contains(9) ? ui->box9R->setChecked(true) : ui->box9R->setChecked(false);

    ui->sliderB->setValue(settings->cellColor.blue());
    ui->sliderG->setValue(settings->cellColor.green());
    ui->sliderR->setValue(settings->cellColor.red());

    cell.fill(settings->cellColor);
    ui->colorLabelCell->setPixmap(cell);

    ui->sliderB->setValue(settings->cellColor.blue());
    ui->sliderG->setValue(settings->cellColor.green());
    ui->sliderR->setValue(settings->cellColor.red());

    bkg.fill(settings->bkgColor);
    ui->colorLabelBkg->setPixmap(bkg);

    ui->sliderB_2->setValue(settings->bkgColor.blue());
    ui->sliderG_2->setValue(settings->bkgColor.green());
    ui->sliderR_2->setValue(settings->bkgColor.red());

    ui->lineX->setText(tr("%1").arg(settings->gameAreaSize.width()));
    ui->lineY->setText(tr("%1").arg(settings->gameAreaSize.height()));

    ui->boxShapes->setCurrentIndex(static_cast<int>(settings->shape));

}
