#ifndef CELL_H
#define CELL_H

#include <QRect>
#include <QColor>
#include <QPixmap>



class Cell
{
public:
    Cell(QPoint p=QPoint(0,0), QSize s=QSize(10,10)) :
        point(p)
    {
        point= p;
        size= s;

        rect = QRect(point,size);
        currentState = nextState = false;
    }

private:
    QSize size;
    QRect rect;
    QPoint point;

    bool currentState;
    bool nextState;
    unsigned int currentNeighboursNumber;

public:
    void SetSize(QSize s) {size= s;}
    void SetPoint(QPoint p) {point= p;}
    void Kill();
    void Revive();

    void UpdateState() {currentState = nextState;}

    QSize GetSize(){ return size; }
    QRect GetRect() { return rect; }
    QPoint GetPoint(){ return point; }
    bool IsAlive(){return currentState;}

};

#endif // CELL_H
