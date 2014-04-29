#include "gamearea.h"
#include "ui_gamearea.h"

#include <QPainter>
#include <QDebug>

#define X   1250
#define Y   1000

GameArea::GameArea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameArea)
{
    settings = new GameSettings();

    QSize cellSize = QSize(X/(settings->gameAreaSize.width() +1), Y/(settings->gameAreaSize.height()+1));
    startPoint= this->mapFromGlobal(QCursor::pos());
    startPoint = QPoint(startPoint.x()/cellSize.width(), startPoint.y()/cellSize.height());
    pixmap = QPixmap(X, Y);

    for(int i=0; i<settings->gameAreaSize.height(); ++i)
    {
        cells.append(QList<Cell>());

        for(int j=0; j<settings->gameAreaSize.width(); ++j)
        {
            cells[i].append(Cell(QPoint(cellSize.height()*j, cellSize.width()*i) , cellSize));
        }
    }


    ui->setupUi(this);
    qApp->installEventFilter(this);

    startPoint= this->mapFromGlobal(QCursor::pos());
    startPoint = QPoint(startPoint.x()/cellSize.width(), startPoint.y()/cellSize.height());

    for(int i=-1; i<3; ++i)
        for(int j=-1; j<3; ++j)
        {
            if(rand()%10) cells[startPoint.y()-i][startPoint.x()-j].Revive();
        }

    generationNr = 0;
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

    QBrush brushBkg(settings->bkgColor);
    QBrush brush(settings->bkgColor);
    QPen pen(settings->bkgColor);

    painter.setBrush(brushBkg);
    painter.fillRect(pixmap.rect(), brushBkg);

    painter.setBrush(brush);
    painter.setPen(pen);


    qDebug() << tr("Bkg color: %1 %2 %3").arg(settings->bkgColor.red()).arg(settings->bkgColor.green()).arg(settings->bkgColor.blue());

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

}

