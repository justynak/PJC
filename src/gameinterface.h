#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include <kscreensaver.h>
#include <kdialog.h>
#include "gamescreensaver.h"
#include "gamesetup.h"


#define VERSION "0.1"
class GameInterface : public KScreenSaverInterface
{
public:

    KAboutData* s_aboutData;

    virtual KAboutData* aboutData()
    {
        s_aboutData = new KAboutData("koceansaver", 0,
                    ki18n("KOceanSaver"), VERSION,
                    ki18n("KDE Ocean screensaver<br>Thanks to the following:<br><b>God</b> and his son <b>Son</b>.<br><b>KDE</b> – for making a great desktop to develop for<br><b>Nokia QT</b> - for making a great SDK and IDE<br><b>Blender</b> – for the best 3D designer out there.<br><b>The GNU Compiler</b> - what else can i say<br><b>Python</b> - what else can I say<br><b>John Stamp</b> for his help with KDE implementation<b>SourceForg for hosting the source."),
                    KAboutData::License_GPL,
                    ki18n("Copyright (C) 2008 Justin L. Boss"),
                    KLocalizedString(),
                    "http://koceansaver.sourceforge.net/",
                    "justin@rtechguys.com");
        return s_aboutData;
    }

    // function to create screen saver object
    virtual KScreenSaver* create(WId id)
    {
        s_aboutData = new KAboutData("koceansaver", 0,
                    ki18n("KOceanSaver"), VERSION,
                    ki18n("KDE Ocean screensaver<br>Thanks to the following:<br><b>God</b> and his son <b>Son</b>.<br><b>KDE</b> – for making a great desktop to develop for<br><b>Nokia QT</b> - for making a great SDK and IDE<br><b>Blender</b> – for the best 3D designer out there.<br><b>The GNU Compiler</b> - what else can i say<br><b>Python</b> - what else can I say<br><b>John Stamp</b> for his help with KDE implementation<b>SourceForg for hosting the source."),
                    KAboutData::License_GPL,
                    ki18n("Copyright (C) 2008 Justin L. Boss"),
                    KLocalizedString(),
                    "http://koceansaver.sourceforge.net/",
                    "justin@rtechguys.com");
        return new GameScreenSaver(id);
    }

    // function to create setup dialog for screen saver
    virtual QDialog* setup()
    {

        s_aboutData = new KAboutData("koceansaver", 0,
                    ki18n("KOceanSaver"), VERSION,
                    ki18n("KDE Ocean screensaver<br>Thanks to the following:<br><b>God</b> and his son <b>Son</b>.<br><b>KDE</b> – for making a great desktop to develop for<br><b>Nokia QT</b> - for making a great SDK and IDE<br><b>Blender</b> – for the best 3D designer out there.<br><b>The GNU Compiler</b> - what else can i say<br><b>Python</b> - what else can I say<br><b>John Stamp</b> for his help with KDE implementation<b>SourceForg for hosting the source."),
                    KAboutData::License_GPL,
                    ki18n("Copyright (C) 2008 Justin L. Boss"),
                    KLocalizedString(),
                    "http://koceansaver.sourceforge.net/",
                    "justin@rtechguys.com");
        return new GameSetup();
    }

};

#endif // GAMEINTERFACE_H
