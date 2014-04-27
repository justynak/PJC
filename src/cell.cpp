#include "cell.h"


void Cell::Kill()
{
    nextState = false;
}
void Cell::Revive()
{
    nextState = true;
}
