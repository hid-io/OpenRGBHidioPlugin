#include "OpenRGBSamplePlugin.h"
#include <QHBoxLayout>

bool OpenRGBSamplePlugin::DarkTheme = false;
ResourceManager* OpenRGBSamplePlugin::RMPointer = nullptr;

OpenRGBPluginInfo OpenRGBSamplePlugin::GetPluginInfo()
{
    printf("[OpenRGBSamplePlugin] Loading plugin info.\n");

    OpenRGBPluginInfo info;
    info.Name         = "Sample plugin";
    info.Description  = "Allo allo";
    info.Version  = VERSION_STRING;
    info.Commit  = GIT_COMMIT_ID;
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

    return 1;
}

void OpenRGBSamplePlugin::Load(bool dark_theme, ResourceManager* resource_manager_ptr)
{
    printf("[OpenRGBSamplePlugin] Loading plugin.\n");

    RMPointer                = resource_manager_ptr;
    DarkTheme                = dark_theme;
}


QWidget* OpenRGBSamplePlugin::GetWidget()
{
    printf("[OpenRGBSamplePlugin] Creating widget.\n");

    QWidget* widget =  new QWidget(nullptr);
    QHBoxLayout* layout = new QHBoxLayout();

    widget->setLayout(layout);
    layout->addWidget(new QLabel("Allo, allo?"));

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

OpenRGBSamplePlugin::~OpenRGBSamplePlugin()
{
     printf("[OpenRGBSamplePlugin] Time to free some memory.\n");
}

