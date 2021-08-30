#ifndef OPENRGBSAMPLEPLUGIN_H
#define OPENRGBSAMPLEPLUGIN_H

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
    ~OpenRGBSamplePlugin();

    OpenRGBPluginInfo   GetPluginInfo() override;
    unsigned int        GetPluginAPIVersion() override;

    void                Load(bool dark_theme, ResourceManager* resource_manager_ptr) override;
    QWidget*            GetWidget() override;
    QMenu*              GetTrayMenu() override;
    void                Unload() override;


//    OpenRGBPluginInfo       PInfo;
//    OpenRGBPluginInfo       Initialize(bool, ResourceManager*)   override;
//    QWidget*                CreateGUI(QWidget *Parent)           override;
    static bool             DarkTheme;
    static ResourceManager* RMPointer;

};

#endif // OPENRGBSAMPLEPLUGIN_H
