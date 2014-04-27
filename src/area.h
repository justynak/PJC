#ifndef AREA_H
#define AREA_H

#include <QPaintEvent>
#include <QWidget>
#include <QTimer>
#include "cell.h"


namespace Ui {
class Area;
}

class Area : public QWidget
{

    Q_OBJECT
public:
    explicit Area(QSize s=QSize(170,100), QWidget *parent = 0);
    ~Area();

private:
    Ui::Area *ui;

    QList<QList<Cell> > cells_;
    QSize AreaSize_;
    QPixmap pixmap_;
    unsigned int generationNr;
    QTimer* t;
    QVector<unsigned int> nToStayAlive_;
    QVector<unsigned int> nToRevive_;
    QPoint startPoint_;

public slots:
    void paintEvent(QPaintEvent *);
    bool eventFilter(QObject *obj, QEvent *event);

    void SetPixmap(QPixmap p) {pixmap_ = p;}
    void UpdateGeneration();
    void UpdatePixmap(){repaint();}

    QPixmap GetPixmap() {return pixmap_;}

};


#endif // AREA_H
