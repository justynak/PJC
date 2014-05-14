#ifndef GAMEGameArea_H
#define GAMEGameArea_H

#include <QPaintEvent>
#include <QWidget>
#include <QTimer>
#include <QMouseEvent>

#include "cell.h"
#include "gamesettings.h"

namespace Ui {
class GameArea;
}

class GameArea : public QWidget
{

    Q_OBJECT
public:
    explicit GameArea(QWidget *parent = 0);
    ~GameArea();

private:
    Ui::GameArea *ui;

    QList<QList<Cell> > cells;
    QPixmap pixmap;
    unsigned int generationNr;
    QTimer* t;
    QPoint startPoint;
    GameSettings* settings;



public slots:
    void paintEvent(QPaintEvent *);
    bool eventFilter(QObject *obj, QEvent *event);

    void UpdateGeneration();
    void UpdatePixmap(){repaint();}
};


#endif // GameArea_H
