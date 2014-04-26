#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "area.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QSize s=QSize(170,100), QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QList<QList<Cell> > cells_;
    QSize MainWindowSize_;
    QPixmap pixmap_;
    unsigned int generationNr;
    QTimer* t;
    QVector<unsigned int> nToStayAlive_;
    QVector<unsigned int> nToRevive_;
    QPoint startPoint_;

public slots:
    void paintEvent(QPaintEvent *);
    bool eventFilter(QObject *obj, QEvent *event);

    void SetPixmap(QPixmap p) {pixmap_ = p;}
    void UpdateGeneration();
    void UpdatePixmap(){repaint();}

    QPixmap GetPixmap() {return pixmap_;}
};

#endif // MAINWINDOW_H
