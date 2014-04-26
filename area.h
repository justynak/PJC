#ifndef AREA_H
#define AREA_H

#include "cell.h"
#include <QPaintEvent>
#include <QMainWindow>

enum GameState {Stopped, Started, Uninitialized};

namespace Ui {
class Area;
}

class Area : public QMainWindow
{
    Q_OBJECT

public:
    explicit Area(QSize s=QSize(30,30), QWidget *parent = 0);
    ~Area();

private:
    Ui::Area *ui;

    QList<QList<Cell> > cells_;
    QSize areaSize_;
    QPixmap pixmap_;
    GameState state_;
    unsigned int generationNr;

public slots:
    void paintEvent(QPaintEvent *);

    void Clear();
    void Start();
    void Stop();

    void SetPixmap(QPixmap p) {pixmap_ = p;}
    void UpdateGeneration();
    void UpdatePixmap(){repaint();}

    QPixmap GetPixmap() {return pixmap_;}

};


#endif // AREA_H
