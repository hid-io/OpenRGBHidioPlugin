#ifndef OPENRGBVISUALMAPPLUGIN_H
#define OPENRGBVISUALMAPPLUGIN_H

#include "OpenRGBPluginInterface.h"
#include "ResourceManager.h"

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QWidget>

class OpenRGBSamplePlugin : public QObject, public OpenRGBPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID OpenRGBPluginInterface_IID)
    Q_INTERFACES(OpenRGBPluginInterface)

public:
    ~OpenRGBSamplePlugin() {};

    OpenRGBPluginInfo       PInfo;
    OpenRGBPluginInfo       Initialize(bool, ResourceManager*)   override;
    QWidget*                CreateGUI(QWidget *Parent)           override;
    static bool             DarkTheme;
    static ResourceManager* RMPointer;

};

#endif // OPENRGBVISUALMAPPLUGIN_H
