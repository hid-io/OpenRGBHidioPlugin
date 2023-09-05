#include "OpenRGBSamplePlugin.h"
#include <QQuickWidget>

bool OpenRGBSamplePlugin::DarkTheme = false;
ResourceManager* OpenRGBSamplePlugin::RMPointer = nullptr;

OpenRGBPluginInfo OpenRGBSamplePlugin::GetPluginInfo()
{
    printf("[OpenRGBSamplePlugin] Loading plugin info.\n");

    OpenRGBPluginInfo info;
    info.Name         = "Sample plugin";
    info.Description  = "Allo allo";
    info.Version  = "1234";
    info.Commit  = "5678";
    info.URL  = "https://gitlab.com/OpenRGBDevelopers/sample-plugin";
    info.Icon.load(":/OpenRGBSamplePlugin.png");

    info.Location     =  OPENRGB_PLUGIN_LOCATION_TOP;
    info.Label        =  "Sample plugin";
    info.TabIconString        =  "Sample plugin";
    info.TabIcon.load(":/OpenRGBSamplePlugin.png");

    return info;
}

unsigned int OpenRGBSamplePlugin::GetPluginAPIVersion()
{
    printf("[OpenRGBSamplePlugin] Loading plugin API version.\n");

    return OPENRGB_PLUGIN_API_VERSION;
}

void OpenRGBSamplePlugin::Load(bool dark_theme, ResourceManager* resource_manager_ptr)
{
    printf("[OpenRGBSamplePlugin] Loading plugin.\n");

    RMPointer = resource_manager_ptr;
    DarkTheme = dark_theme;
}


QWidget* OpenRGBSamplePlugin::GetWidget()
{
    printf("[OpenRGBSamplePlugin] Creating widget.\n");

    registerTypes("org.openrgb.plugin.rust_sample");
    QQuickWidget* widget = new QQuickWidget();
    widget->setSource(QUrl("qrc:/qml/main.qml"));
    widget->setResizeMode(QQuickWidget::SizeRootObjectToView); // Resize to fit the plugin view
    return widget;
}

QMenu* OpenRGBSamplePlugin::GetTrayMenu()
{
    printf("[OpenRGBSamplePlugin] Creating tray menu.\n");

    QMenu* menu = new QMenu("Sample plugin");

    return menu;
}

void OpenRGBSamplePlugin::Unload()
{
    printf("[OpenRGBSamplePlugin] Time to call some cleaning stuff.\n");
}

OpenRGBSamplePlugin::OpenRGBSamplePlugin()
{
    printf("[OpenRGBSamplePlugin] Constructor.\n");
}

OpenRGBSamplePlugin::~OpenRGBSamplePlugin()
{
     printf("[OpenRGBSamplePlugin] Time to free some memory.\n");
}

void OpenRGBSamplePlugin::registerTypes(const char* uri)
{
    printf("[OpenRGBSamplePlugin] Registering types.\n");
    qmlRegisterType<core::MyObject>(uri, 1, 0, "MyObject");
}

#include "moc_OpenRGBSamplePlugin.cpp"
