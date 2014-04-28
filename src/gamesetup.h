#ifndef GAMESETUP_H
#define GAMESETUP_H

#include <QDialog>
#include <QPixmap>
#include <kdialog.h>

#include "gamesettings.h"


namespace Ui {
class GameSetup;
}

class GameSetup : public KDialog
{
    Q_OBJECT

public:
    explicit GameSetup(QWidget *parent = 0);
    ~GameSetup();

private :
    GameSettings* settings;
    QPixmap bkg;
    QPixmap cell;

private slots:
    void onSliderRValueChanged(int value);
    void onSliderGValueChanged(int value);
    void onSliderBValueChanged(int value);
    void onSliderR_2ValueChanged(int value);
    void onSliderG_2ValueChanged(int value);
    void onSliderB_2ValueChanged(int value);

    void ShowSettings();

    void onOkClicked();
    void onHelpClicked();
    void onDefaultClicked();

private:
    Ui::GameSetup *ui;
};

#endif // GAMESETUP_H
