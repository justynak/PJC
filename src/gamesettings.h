#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H

#include <kdialog.h>
#include <QVector>

enum Shape {Rect=0, RoundedRect, Ellipse};


class GameSettings
{
public:
    GameSettings();

    QList<unsigned int> nToStayAlive;
    QList<unsigned int> nToRevive;
    QColor color;
    QSize gameAreaSize;
    Shape shape;

    void Load();
    void RestoreDefault();
    void Save();

};

#endif // GAMESETTINGS_H
