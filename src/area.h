#ifndef AREA_H
#define AREA_H


#include "cell.h"
#include "gamesettings.h"
#include <QList>


class Area
{

public:
    Area(int X, int Y);
    virtual ~Area();
    void UpdateGeneration();
    void KillCell(int i, int j);
    void ReviveCell(int i, int j);
    bool IsAlive(int i, int j);

    void SetRules(QList<unsigned int> list1, QList<unsigned int> list2);


private:
    QList<QList<Cell> > cells;
    QList<unsigned int> nToStayAlive;
    QList<unsigned int> nToRevive;


};

#endif // AREA_H
