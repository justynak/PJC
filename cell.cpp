#include "cell.h"


void Cell::Kill()
{
    nextState_ = false;
    //pixmap_.fill(QColor(255,255,255));
}
void Cell::Revive()
{
    nextState_ = true;
    //pixmap_.fill(QColor(255,0,0));
}
