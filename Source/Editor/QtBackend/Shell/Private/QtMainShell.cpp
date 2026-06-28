// Copyright XYBEngine. All Rights Reserved.
//
// QtMainShell.cpp - 编辑器主窗口 Qt 实现

#include "QtMainShell.h"
#include "ui_QtMainShell.h"
#include "QtHelper.h"

namespace XYBEngine
{
    QtMainShell::QtMainShell(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::QtMainShell)
    {
        ui->setupUi(this);
        // 从 Qt 资源系统加载皮肤样式表（qrc:/Skin/...）
        QString _styleSheet = QtHelper::ReadStringFromFile(":/Skin/Skin/Unreal.skin");
        this->setStyleSheet(_styleSheet);   
    }

    QtMainShell::~QtMainShell()
    {
        delete ui;
    }

    void QtMainShell::Initialize()
    {
    }

    void QtMainShell::Show()
    {
        this->show();
    }

    void QtMainShell::Hide()
    {
        this->hide();
    }

    void QtMainShell::Close()
    {
        this->close();
    }
 
    void QtMainShell::AddPanel(const String& defaultArea, SharedPtr<IEditorPanel> panel)
    { 
        if (defaultArea == "Left")
        {
            ui->Dock_LeftLayout->layout()->addWidget(static_cast<QWidget*>(panel->GetNativeView()));
        }  
        else if (defaultArea == "Bottom")
        {
            ui->Dock_BottomLayout->layout()->addWidget(static_cast<QWidget*>(panel->GetNativeView()));
        }
        else if (defaultArea == "Center")
        {
            ui->Dock_CenterLayout->layout()->addWidget(static_cast<QWidget*>(panel->GetNativeView()));
        }
        else
        {
            XYB_LOG_ERROR("Invalid default area");
        }
    }

    void QtMainShell::TogglePanel(const String& panelId)
    { 
    }
}
