#include "area.h"

Area::Area(int X, int Y)
{
    for(int i=0; i<X; ++i)
    {
        cells.append(QList<Cell>());

        for(int j=0; j<Y; ++j)
        {
            cells[i].append(Cell());
        }
    }

}

Area::~Area()
{
    for(int i=0; i<cells.size(); ++i)
    {
        cells[i].clear();
    }

    cells.clear();
    nToRevive.clear();
    nToStayAlive.clear();
}


void Area::UpdateGeneration()
{
    unsigned int n = 0;
    for(int i=1; i< cells.size() -1 ; ++i)
        for(int j=1; j<cells[i].size()-1 ; ++j)
            {
                n = cells[i-1][j-1].IsAlive() + cells[i-1][j].IsAlive() + cells[i-1][j+1].IsAlive()
                            + cells[i][j-1].IsAlive() + cells[i][j+1].IsAlive() +
                            cells[i+1][j-1].IsAlive() + cells[i+1][j].IsAlive() + cells[i+1][j+1].IsAlive();

                if(cells[i][j].IsAlive())
                {
                    int k = nToStayAlive.indexOf(n);
                    if(k==-1) cells[i][j].Kill();
                }
                else
                {
                    int k = nToRevive.indexOf(n);
                    if(k!=-1) cells[i][j].Revive();
                }
            }


    for(int i=0; i< cells.size() ; ++i)
        for(int j=0; j<cells[i].size(); ++j)
            {
                cells[i][j].UpdateState();
            }

}

void Area::KillCell(int i, int j)
{
    cells[i][j].Kill();
}

void Area::ReviveCell(int i, int j)
{
    cells[i][j].Revive();
}

bool Area::IsAlive(int i, int j)
{
    return cells[i][j].IsAlive();
}

void Area::SetRules(QList<unsigned int> list1, QList<unsigned int> list2)
{
    this->nToRevive = list1;
    this->nToStayAlive = list2;
}







