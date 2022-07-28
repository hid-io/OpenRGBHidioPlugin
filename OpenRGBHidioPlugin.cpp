#include "OpenRGBHidioPlugin.h"
#include <QHBoxLayout>

bool OpenRGBHidioPlugin::DarkTheme = false;
ResourceManager* OpenRGBHidioPlugin::RMPointer = nullptr;

OpenRGBPluginInfo OpenRGBHidioPlugin::GetPluginInfo()
{
    printf("[OpenRGBHidioPlugin] Loading plugin info.\n");

    OpenRGBPluginInfo info;
    info.Name = "HID-IO";
    info.Description = "The hid-io plugin uses the Cap'n'Proto API interface to communicate with hid-io supported input devices.";
    info.Version = VERSION_STRING;
    info.Commit = GIT_COMMIT_ID;
    info.URL = "https://github.com/hid-io/OpenRGBHidioPlugin";
    info.Icon.load(":/OpenRGBHidioPlugin.png");

    info.Location = OPENRGB_PLUGIN_LOCATION_TOP;
    info.Label = "HID-IO";
    info.TabIconString = "HID-IO";
    info.TabIcon.load(":/OpenRGBHidioPlugin.png");

    return info;
}

unsigned int OpenRGBHidioPlugin::GetPluginAPIVersion()
{
    printf("[OpenRGBHidioPlugin] Loading plugin API version.\n");

    return OPENRGB_PLUGIN_API_VERSION;
}

void OpenRGBHidioPlugin::Load(bool dark_theme, ResourceManager* resource_manager_ptr)
{
    printf("[OpenRGBHidioPlugin] Loading plugin.\n");

    RMPointer                = resource_manager_ptr;
    DarkTheme                = dark_theme;
}


QWidget* OpenRGBHidioPlugin::GetWidget()
{
    printf("[OpenRGBHidioPlugin] Creating widget.\n");

    QWidget* widget =  new QWidget(nullptr);
    QHBoxLayout* layout = new QHBoxLayout();

    widget->setLayout(layout);
    layout->addWidget(new QLabel("Allo, allo?"));

    return widget;
}

QMenu* OpenRGBHidioPlugin::GetTrayMenu()
{
    printf("[OpenRGBHidioPlugin] Creating tray menu.\n");

    QMenu* menu = new QMenu("Sample plugin");

    return menu;
}

void OpenRGBHidioPlugin::Unload()
{
    printf("[OpenRGBHidioPlugin] Time to call some cleaning stuff.\n");
}

OpenRGBHidioPlugin::OpenRGBHidioPlugin()
{
    printf("[OpenRGBHidioPlugin] Constructor.\n");
}

OpenRGBHidioPlugin::~OpenRGBHidioPlugin()
{
     printf("[OpenRGBHidioPlugin] Time to free some memory.\n");
}

