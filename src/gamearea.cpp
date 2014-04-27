#include "gamearea.h"
#include "ui_gamearea.h"

#include <QPainter>
#include <QDebug>



GameArea::GameArea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameArea)
{


    startPoint= this->mapFromGlobal(QCursor::pos());
    startPoint = QPoint(startPoint.x()/10, startPoint.y()/10);
    qDebug() << tr("Mouse position: %1, %2").arg(startPoint.x()).arg(startPoint.y());


    settings = new GameSettings();

    QSize cellSize = QSize(1700/settings->gameAreaSize.height(), 1000/settings->gameAreaSize.width());
    QPoint translation = QPoint(1700%settings->gameAreaSize.height(), 1000%settings->gameAreaSize.width());


    for(int i=0; i<settings->gameAreaSize.height(); ++i)
    {
        cells.append(QList<Cell>());

        for(int j=0; j<settings->gameAreaSize.width(); ++j)
        {
            cells[i].append(Cell(QPoint(cellSize.height()*j, cellSize.width()*i) + translation, cellSize));
        }
    }
    qApp->installEventFilter(this);

    for(int i=-1; i<3; ++i)
        for(int j=-1; j<3; ++j)
        {
            if(rand()%10) cells[startPoint.y()-i][startPoint.x()-j].Revive();
        }

    ui->setupUi(this);


    generationNr = 0;
    ui->label2->setText(tr("Generation number: %1").arg(generationNr));
    repaint();
    qDebug() << "GameArea created";
    t = new QTimer();
    t->start(200);
    connect(t, SIGNAL(timeout()), this, SLOT(UpdateGeneration()));

}

GameArea::~GameArea()
{
    delete ui;
    delete t;
}


void GameArea::UpdateGeneration()
{
    unsigned int n = 0;
    for(int i=1; i< settings->gameAreaSize.height() -1 ; ++i)
        for(int j=1; j<settings->gameAreaSize.width() -1 ; ++j)
            {
                n = cells[i-1][j-1].IsAlive() + cells[i-1][j].IsAlive() + cells[i-1][j+1].IsAlive()
                            + cells[i][j-1].IsAlive() + cells[i][j+1].IsAlive() +
                            cells[i+1][j-1].IsAlive() + cells[i+1][j].IsAlive() + cells[i+1][j+1].IsAlive();

                if(cells[i][j].IsAlive())
                {
                    int k = settings->nToStayAlive.indexOf(n);
                    if(k==-1) cells[i][j].Kill();
                }
                else
                {
                    int k = settings->nToRevive.indexOf(n);
                    if(k!=-1) cells[i][j].Revive();
                }
            }


    for(int i=0; i< settings->gameAreaSize.height() ; ++i)
        for(int j=0; j<settings->gameAreaSize.width(); ++j)
            {
                cells[i][j].UpdateState();
            }

    ui->label2->setText(tr("Generation number: %1").arg(generationNr ++));
    repaint();
}



bool GameArea::eventFilter(QObject *obj, QEvent *event)
{
  if (event->type() == QEvent::MouseMove)
  {
    QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
    if(mouseEvent->pos().y()<0 || mouseEvent->pos().x()<0) return false;
    else
    cells[mouseEvent->pos().y()/10][mouseEvent->pos().x()/10].Revive();
   // qDebug() << QString("Mouse move (%1,%2)").arg(mouseEvent->pos().x()).arg(mouseEvent->pos().y());
  }
  return false;
}


void GameArea::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QBrush brush(QColor(0,0,0));
    QPen pen(QColor(0xE8, 0xDA, 0xB8));
    painter.setPen(pen);

    painter.setBrush(brush);
    pixmap.fill(settings->bkgColor);

    for(int i=0; i<settings->gameAreaSize.height() -1; ++i)
        for(int j =0; j<settings->gameAreaSize.width() -1 ; ++j)
        {
            if(cells[i][j].IsAlive())
            {
             brush.setColor(settings->cellColor);
             painter.setBrush(brush);

             switch(settings->shape)
             {
                case Rect: painter.drawRect(cells[i][j].GetRect()); break;
                case RoundedRect: painter.drawRoundedRect(cells[i][j].GetRect(), 5, 5); break;
                case Ellipse: painter.drawEllipse(cells[i][j].GetRect()); break;
                default: break;
             }
            }
        }

    ui->label->setPixmap(pixmap);
}

