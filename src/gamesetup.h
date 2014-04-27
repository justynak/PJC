#ifndef GAMESETUP_H
#define GAMESETUP_H

#include <QDialog>
#include "gamesettings.h"
#include <QPixmap>

namespace Ui {
class GameSetup;
}

class GameSetup : public QDialog
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
    void on_sliderR_valueChanged(int value);

    void on_sliderG_valueChanged(int value);

    void on_sliderB_valueChanged(int value);

    void on_sliderR_2_valueChanged(int value);

    void on_sliderG_2_valueChanged(int value);

    void on_sliderB_2_valueChanged(int value);

    void on_buttonDefault_clicked();

    void on_buttonOk_clicked();

    void on_buttonExit_clicked();

private:
    Ui::GameSetup *ui;
};

#endif // GAMESETUP_H
