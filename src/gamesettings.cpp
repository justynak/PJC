#include <ksharedconfig.h>
#include <kconfiggroup.h>

#include "gamesettings.h"

GameSettings::GameSettings()
{
    Load();
}

void GameSettings::Load()
{
    QList<unsigned int> list1 = QList<unsigned int>();
    list1.append(2);

    QList<unsigned int> list2 = QList<unsigned int>();
    list2.append(2);
    list2.append(3);

    /*
     * key, default value
     */


    KConfigGroup config( KGlobal::config(), "Settings" );
    nToRevive = config.readEntry("nToRevive", list1);
    nToStayAlive = config.readEntry("nToStayAlive", list2);
    color = config.readEntry("Color", QColor(100, 100, 100));
    gameAreaSize = config.readEntry("GameAreaSize", QSize(170, 100));
    shape = static_cast<Shape>(config.readEntry("Shape", (static_cast<int>(Rect))));
}

void GameSettings::RestoreDefault()
{
    //nToRevive = QList<int>({2});
    //nToStayAlive =  QList<int>({2,3});
    color = QColor(100, 100, 100);
    gameAreaSize =  QSize(170, 100);
    shape = Rect;
}

void GameSettings::Save()
{
    KConfigGroup config( KGlobal::config(), "Settings" );
    config.writeEntry("nToRevive", nToRevive);
    config.writeEntry("nToStayAlive", nToStayAlive);
    config.writeEntry("Color", color);
    config.writeEntry("GameAreaSize", gameAreaSize);
    config.writeEntry("Shape", static_cast<int>(shape));
}
