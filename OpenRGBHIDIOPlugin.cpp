#include "OpenRGBHIDIOPlugin.h"
#include <QQuickWidget>

bool OpenRGBHIDIOPlugin::DarkTheme = false;
ResourceManager* OpenRGBHIDIOPlugin::RMPointer = nullptr;

OpenRGBPluginInfo OpenRGBHIDIOPlugin::GetPluginInfo()
{
    printf("[OpenRGBHIDIOPlugin] Loading plugin info.\n");

    OpenRGBPluginInfo info;
    info.Name = "HID-IO";
    info.Description  = "HID-IO plugin interface for OpenRGB.\nRequires a hid-io-core instance running in the background to function.";
    info.Version  = "1234"; // TODO pull from rust
    info.Commit  = "5678"; // TODO pull from rust
    info.URL  = "https://github.com/hid-io/OpenRGBHidioPlugin";
    info.Icon.load(":/hid-io.png");

    info.Location =  OPENRGB_PLUGIN_LOCATION_TOP;
    info.Label =  "HID-IO";
    info.TabIconString = "HID-IO";
    info.TabIcon.load(":/OpenRGBHIDIOPlugin.png");

    return info;
}

unsigned int OpenRGBHIDIOPlugin::GetPluginAPIVersion()
{
    return OPENRGB_PLUGIN_API_VERSION;
}

void OpenRGBHIDIOPlugin::Load(bool dark_theme, ResourceManager* resource_manager_ptr)
{
    printf("[OpenRGBHIDIOPlugin] Loading plugin.\n");

    RMPointer = resource_manager_ptr;
    DarkTheme = dark_theme;
}


QWidget* OpenRGBHIDIOPlugin::GetWidget()
{
    printf("[OpenRGBHIDIOPlugin] Creating widget.\n");

    registerTypes("com.hidio.openrgb.plugin");
    QQuickWidget* widget = new QQuickWidget();
    widget->setSource(QUrl("qrc:/qml/main.qml"));
    widget->setResizeMode(QQuickWidget::SizeRootObjectToView); // Resize to fit the plugin view
    return widget;
}

QMenu* OpenRGBHIDIOPlugin::GetTrayMenu()
{
    printf("[OpenRGBHIDIOPlugin] Creating tray menu.\n");

    // TODO
    // - Start/stop hid-io-core
    //   * systemd linux
    //   * launchd macos
    //   * service windows
    // - Show hid-io status
    // - Show connected devices
    QMenu* menu = new QMenu("HID-IO");

    return menu;
}

void OpenRGBHIDIOPlugin::Unload()
{
    printf("[OpenRGBHIDIOPlugin] Time to call some cleaning stuff.\n");
}

OpenRGBHIDIOPlugin::OpenRGBHIDIOPlugin()
{
    printf("[OpenRGBHIDIOPlugin] Constructor.\n");
}

OpenRGBHIDIOPlugin::~OpenRGBHIDIOPlugin()
{
     printf("[OpenRGBHIDIOPlugin] Time to free some memory.\n");
}

void OpenRGBHIDIOPlugin::registerTypes(const char* uri)
{
    printf("[OpenRGBHIDIOPlugin] Registering types.\n");
    qmlRegisterType<core::MyObject>(uri, 1, 0, "MyObject");
}

#include "moc_OpenRGBHIDIOPlugin.cpp"
