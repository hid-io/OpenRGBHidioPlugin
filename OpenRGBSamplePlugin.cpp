#include "OpenRGBSamplePlugin.h"
#include <QHBoxLayout>

bool OpenRGBSamplePlugin::DarkTheme = false;
ResourceManager* OpenRGBSamplePlugin::RMPointer = nullptr;

OpenRGBPluginInfo OpenRGBSamplePlugin::Initialize(bool Dt, ResourceManager *RM)
{
    PInfo.PluginName         = "Sample plugin";
    PInfo.PluginDescription  = "Allo allo";
    PInfo.PluginLocation     = "TopTabBar";
    PInfo.HasCustom          = true;
    PInfo.PluginLabel        = new QLabel("Sample plugin");

    RMPointer                = RM;
    DarkTheme                = Dt;

    return PInfo;
}

QWidget* OpenRGBSamplePlugin::CreateGUI(QWidget* parent)
{  
    QWidget* widget =  new QWidget(nullptr);
    QHBoxLayout* layout = new QHBoxLayout();
    widget->setLayout(layout);

    layout->addWidget(new QLabel("Allo, allo?"));

    return widget;
}
