#include "area.h"
#include "ui_area.h"

#include <QPainter>
#include <QDebug>


Area::Area( QSize s, QWidget *parent) :
    QMainWindow(parent)
{

    for(int i=0; i<s.height(); ++i)
    {
        cells_.append(QList<Cell>());

        for(int j=0; j<s.width(); ++j)
        {
            cells_[i].append(Cell());
        }
    }
    repaint();
    qDebug() << "Area created";

}

Area::~Area()
{
}

void Area::Clear()
{
    //disconnect(coś, SIGNAL(startapp), this, SLOT(UpdateGeneration)));
    repaint();
}

void Area::Start()
{
    state_ = Started;
    repaint();
    //connect(coś, SIGNAL(startapp), this, SLOT(UpdateGeneration)));
}

void Area::Stop()
{
    state_ = Stopped;
    //disconnect(coś, SIGNAL(startapp), this, SLOT(UpdateGeneration)));
}

void Area::UpdateGeneration()
{
    unsigned int neighbours = 0;
    for(int i=1; i< areaSize_.height() -1; ++i)
        for(int j=1; j<areaSize_.width() -1; ++j)
            {
                neighbours = cells_[i-1][j-1].IsAlive() + cells_[i-1][j].IsAlive() + cells_[i-1][j+1].IsAlive()
                            + cells_[i][j-1].IsAlive() + cells_[i][j+1].IsAlive() +
                            cells_[i+1][j-1].IsAlive() + cells_[i+1][j].IsAlive() + cells_[i+1][j+1].IsAlive();

                //cells_[i][j].CheckNeighbours(neighbours);
            }
    for(int i=1; i< areaSize_.height() -1; ++i)
        for(int j=1; j<areaSize_.width() -1; ++j)
            {
                cells_[i][j].UpdateState();
            }
    generationNr ++;
    repaint();
}

void Area::paintEvent(QPaintEvent *)
{
    QPainter painter(&pixmap_);

    for(int i=0; i<areaSize_.height(); ++i)
        for(int j =0; j<areaSize_.width(); ++j)
        {
            QPoint p(cells_[i][j].GetPoint());
            //painter.drawPixmap(p, cells_[j][j].GetPixmap());
        }

    //qDebug() << "Paint updated";
}

