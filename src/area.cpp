#include "area.h"
#include "ui_area.h"

#include <QPainter>
#include <QDebug>



Area::Area( QSize s, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Area)
{


    startPoint_= this->mapFromGlobal(QCursor::pos());
    startPoint_ = QPoint(startPoint_.x()/10, startPoint_.y()/10);
    qDebug() << tr("Mouse position: %1, %2").arg(startPoint_.x()).arg(startPoint_.y());
    AreaSize_ = s;

    for(int i=0; i<AreaSize_.height(); ++i)
    {
        cells_.append(QList<Cell>());

        for(int j=0; j<AreaSize_.width(); ++j)
        {
            cells_[i].append(Cell(Rect, QPoint(10*j, 10*i)));
            //if(qrand()%2==0) cells_[i][j].Revive();
        }
    }
    qApp->installEventFilter(this);

    for(int i=-1; i<3; ++i)
        for(int j=-1; j<3; ++j)
        {
            if(rand()%10) cells_[startPoint_.y()-i][startPoint_.x()-j].Revive();
        }

    ui->setupUi(this);

/*
    nToStayAlive_.append(2);
    nToStayAlive_.append(3);
    nToRevive_.append(3);
    */

    nToStayAlive_.append(4);
    nToStayAlive_.append(5);
    nToStayAlive_.append(6);
    nToStayAlive_.append(7);
    nToStayAlive_.append(8);
    nToRevive_.append(3);

    generationNr = 0;
    ui->label_2->setText(tr("Generation number: %1").arg(generationNr));
    repaint();
    qDebug() << "Area created";
    t = new QTimer();
    t->start(200);
    connect(t, SIGNAL(timeout()), this, SLOT(UpdateGeneration()));

}

Area::~Area()
{
    delete ui;
    delete t;
}


void Area::UpdateGeneration()
{
    unsigned int n = 0;
    for(int i=1; i< AreaSize_.height() -1 ; ++i)
        for(int j=1; j<AreaSize_.width() -1 ; ++j)
            {
                n = cells_[i-1][j-1].IsAlive() + cells_[i-1][j].IsAlive() + cells_[i-1][j+1].IsAlive()
                            + cells_[i][j-1].IsAlive() + cells_[i][j+1].IsAlive() +
                            cells_[i+1][j-1].IsAlive() + cells_[i+1][j].IsAlive() + cells_[i+1][j+1].IsAlive();

                if(cells_[i][j].IsAlive())
                {
                    int k = nToStayAlive_.indexOf(n);
                    if(k==-1) cells_[i][j].Kill();
                }
                else
                {
                    int k = nToRevive_.indexOf(n);
                    if(k!=-1) cells_[i][j].Revive();
                }
            }


    for(int i=0; i< AreaSize_.height() ; ++i)
        for(int j=0; j<AreaSize_.width(); ++j)
            {
                cells_[i][j].UpdateState();
            }

    ui->label_2->setText(tr("Generation number: %1").arg(generationNr ++));
    repaint();
}

/*
void Area::mouseMoveEvent(QMouseEvent *event)
{
    QPoint p= this->mapFromGlobal(QCursor::pos());
    cells_[p.y()/10][p.x()/10].Revive();
    qDebug() << event->pos();
}
*/

bool Area::eventFilter(QObject *obj, QEvent *event)
{
  if (event->type() == QEvent::MouseMove)
  {
    QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
    if(mouseEvent->pos().y()<0 || mouseEvent->pos().x()<0) return false;
    else
    cells_[mouseEvent->pos().y()/10][mouseEvent->pos().x()/10].Revive();
   // qDebug() << QString("Mouse move (%1,%2)").arg(mouseEvent->pos().x()).arg(mouseEvent->pos().y());
  }
  return false;
}


void Area::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QBrush brush(QColor(0,0,0));
    QPen pen(QColor(0xE8, 0xDA, 0xB8));
    painter.setPen(pen);

    painter.setBrush(brush);

    for(int i=0; i<AreaSize_.height() -1; ++i)
        for(int j =0; j<AreaSize_.width() -1 ; ++j)
        {
            if(cells_[i][j].IsAlive())
            {
             brush.setColor(QColor(0xFF, 0x50, 0x9F));
             painter.setBrush(brush);
             //painter.drawEllipse(cells_[i][j].GetRect());
             painter.drawRect(cells_[i][j].GetRect());

            }


            QPoint p(cells_[i][j].GetPoint());
            //qDebug() << tr("Paint updated, last point: (%1, %2)").arg(i).arg(j);

        }
    ui->label->setPixmap(pixmap_);

}

