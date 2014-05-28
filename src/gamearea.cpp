#include "gamearea.h"
#include "ui_gamearea.h"

#include <QPainter>
#include <QDebug>

#define X   1250
#define Y   1000

GameArea::GameArea(QWidget *parent) :
    ui(new Ui::GameArea)
{
    settings = new GameSettings();

    pixmap = new QPixmap(X, Y);
    cellSize = new QSize(X/(settings->gameAreaSize.width() +1), Y/(settings->gameAreaSize.height()+1));

    area = new Area(settings->gameAreaSize.width(), settings->gameAreaSize.height());
    area->SetRules(settings->nToRevive, settings->nToStayAlive);

    //setup UI
    ui->setupUi(this);
    qApp->installEventFilter(this);

    QPoint startPoint= this->mapFromGlobal(QCursor::pos());
    startPoint = QPoint(startPoint.x()/cellSize->width(), startPoint.y()/cellSize->height());

    for(int i=-1; i<3; ++i)
        for(int j=-1; j<3; ++j)
        {
            if(rand()%10) area->ReviveCell(startPoint.x()-i, startPoint.y()-j);
        }

    repaint();
    qDebug() << "GameArea created";


    t = new QTimer();
    t->start(200);
    connect(t, SIGNAL(timeout()), this, SLOT(UpdatePixmap()));
}

GameArea::~GameArea()
{
    delete ui;
    delete t;
    delete area;
    delete cellSize;
    delete pixmap;
    delete settings;
}




bool GameArea::eventFilter(QObject *obj, QEvent *event)
{
  if (event->type() == QEvent::MouseMove)
  {
    QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
    if(mouseEvent->pos().y()<0 || mouseEvent->pos().x()<0) return false;
    else
    area->ReviveCell(mouseEvent->pos().y()/10, mouseEvent->pos().x()/10);
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
    painter.fillRect(pixmap->rect(), brushBkg);

    painter.setBrush(brush);
    painter.setPen(pen);


    qDebug() << tr("Bkg color: %1 %2 %3").arg(settings->bkgColor.red()).arg(settings->bkgColor.green()).arg(settings->bkgColor.blue());

    for(int i=0; i<settings->gameAreaSize.width() -1; ++i)
        for(int j =0; j<settings->gameAreaSize.height() -1 ; ++j)
        {
            if(area->IsAlive(i, j))
            {
             brush.setColor(settings->cellColor);

             painter.setBrush(brush);

             QPoint point = QPoint(X/settings->gameAreaSize.width()*i, Y/settings->gameAreaSize.height()*j);
             QRect rect = QRect(point, *cellSize);

             switch(settings->shape)
             {
                case Rect: painter.drawRect(rect); break;
                case RoundedRect: painter.drawRoundedRect(rect, 5, 5); break;
                case Ellipse: painter.drawEllipse(rect); break;
                default: break;
             }
           }
         }

}

