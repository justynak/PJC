#ifndef CELL_H
#define CELL_H

#include <QRect>
#include <QColor>
#include <QPixmap>



class Cell
{
public:
    Cell()
    {
        currentState = nextState = false;
    }

private:
    bool currentState;
    bool nextState;

public:
    void Kill();
    void Revive();

    void UpdateState() {currentState = nextState;}

    bool IsAlive(){return currentState;}

};

#endif // CELL_H
