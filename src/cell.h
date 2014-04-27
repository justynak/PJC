#ifndef CELL_H
#define CELL_H

#include <QRect>
#include <QColor>
#include <QPixmap>

enum Shape {Rect, RoundedRect, Ellipse, Pixmap };


class Cell
{
public:
    Cell(Shape sh=Rect, QPoint p=QPoint(0,0), QSize s=QSize(10,10)) :
        point_(p)
    {
       /*
        QString file;
        switch(shape_)
        {
            case Rect:          file = ""; break;
            case RoundedRect:   file = ""; break;
            case Ellipse:       file = ""; break;
            case Pixmap:        file = ""; break;
        }
        pixmap_.load(file);
        //for now

        //pixmap_ = QPixmap(QSize(10,10));
        //pixmap_.fill(QColor(255,255,255));
        */

        point_ = p;
        size_ = s;

        rect_ = QRect(point_,size_);
        currentState_ = nextState_ = false;
    }

private:
    QSize size_;
    QRect rect_;
    //QPixmap pixmap_;
    //Shape shape_;
    QPoint point_;

    bool currentState_;
    bool nextState_;
    unsigned int currentNeighboursNumber_;

public:
    void SetSize(QSize s) {size_ = s;}
    void SetPoint(QPoint p) {point_ = p;}
    void Kill();
    void Revive();

    void UpdateState() {currentState_ = nextState_;}

    QSize GetSize(){ return size_; }
    QRect GetRect() { return rect_; }
    QPoint GetPoint(){ return point_; }
    //QPixmap GetPixmap(){return pixmap_;}
    //Shape GetShape(){return shape_;}
    bool IsAlive(){return currentState_;}

};

#endif // CELL_H
