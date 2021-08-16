#include "OpenRGBSamplePlugin.h"
#include <QHBoxLayout>

bool OpenRGBSamplePlugin::DarkTheme = false;
ResourceManager* OpenRGBSamplePlugin::RMPointer = nullptr;

OpenRGBPluginInfo OpenRGBSamplePlugin::Initialize(bool Dt, ResourceManager *RM)
{
    PInfo.PluginName         = "Sample plugin";
    PInfo.PluginDescription  = "Allo allo";       

    /*-----------------------------------------------------*\
    |     PInfo.PluginLocation                              |
    |                                                       |
    | InformationTab - Place plugin in the Information tab  |
    | DevicesTab - Place plugin in the Devices tab          |
    | TopTabBar - Place plugin as its own top level tab     |
    | SettingsTabBar - Place plugin in the Settings tab     |
    \*-----------------------------------------------------*/
    PInfo.PluginLocation     = "TopTabBar";
    PInfo.HasCustom          = true;
    PInfo.PluginLabel        = new QLabel("Sample plugin");

    RMPointer                = RM;
    DarkTheme                = Dt;

    return PInfo;
}

QWidget* OpenRGBSamplePlugin::CreateGUI(QWidget* parent)
{  
    // Retuning a dummy QWidget with a label
    QWidget* widget =  new QWidget(parent);

    QHBoxLayout* layout = new QHBoxLayout();
    widget->setLayout(layout);
    layout->addWidget(new QLabel("Allo, allo?"));

    return widget;
}
