#ifndef OPENRGBHIDIOPLUGIN_H
#define OPENRGBHIDIOPLUGIN_H

#include "OpenRGBPluginInterface.h"
#include "ResourceManager.h"

#undef u8
#undef u16
#undef u32
#undef s32

#include <QtQml/QQmlExtensionPlugin>

#include "cxx-qt-gen/my_object.cxxqt.h"

class OpenRGBHIDIOPlugin : public QQmlExtensionPlugin, public OpenRGBPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID OpenRGBPluginInterface_IID)
    Q_INTERFACES(OpenRGBPluginInterface)

public:
    OpenRGBHIDIOPlugin();
    ~OpenRGBHIDIOPlugin();

    OpenRGBPluginInfo   GetPluginInfo() override;
    unsigned int        GetPluginAPIVersion() override;

    void                Load(bool dark_theme, ResourceManager* resource_manager_ptr) override;
    QWidget*            GetWidget() override;
    QMenu*              GetTrayMenu() override;
    void                Unload() override;
    void                registerTypes(const char* uri) override;

//    OpenRGBPluginInfo       PInfo;
//    OpenRGBPluginInfo       Initialize(bool, ResourceManager*)   override;
//    QWidget*                CreateGUI(QWidget *Parent)           override;
    static bool             DarkTheme;
    static ResourceManager* RMPointer;
};

#endif // OPENRGBHIDIOPLUGIN_H
