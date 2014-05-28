#ifndef GAMEGameArea_H
#define GAMEGameArea_H

#include <QPaintEvent>
#include <QWidget>
#include <QTimer>
#include <QMouseEvent>

#include "gamesettings.h"
#include "area.h"
namespace Ui {
class GameArea;
}

class GameArea : public QWidget
{

    Q_OBJECT
public:
    explicit GameArea(QWidget *parent = 0);
    virtual ~GameArea();

private:
    Ui::GameArea *ui;
    Area* area;
    QPixmap* pixmap;
    QTimer* t;
    GameSettings* settings;

    QSize* cellSize;


public slots:
    void paintEvent(QPaintEvent *);
    bool eventFilter(QObject *obj, QEvent *event);

    void UpdatePixmap(){area->UpdateGeneration();repaint();}
};


#endif // GameArea_H
