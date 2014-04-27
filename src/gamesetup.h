#ifndef GAMESETUP_H
#define GAMESETUP_H

#include <QDialog>

namespace Ui {
class GameSetup;
}

class GameSetup : public QDialog
{
    Q_OBJECT

public:
    explicit GameSetup(QWidget *parent = 0);
    ~GameSetup();

private:
    Ui::GameSetup *ui;
};

#endif // GAMESETUP_H
