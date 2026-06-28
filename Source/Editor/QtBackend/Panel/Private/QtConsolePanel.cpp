// Copyright XYBEngine. All Rights Reserved.
//
// QtConsolePanel.cpp - 控制台 Qt 控件实现

#include "QtConsolePanel.h"
#include "ui_QtConsolePanel.h" 
#include "QtHelper.h" 
 
namespace XYBEngine
{ 
    namespace EditorPanelIds
    {
        inline constexpr const char* Console  = "Console";
    }

    static SharedPtr<IEditorPanel> CreateConsolePanel()
    {
        return MakeShared<QtConsolePanel>();
    }

    void QtConsolePanelResiter()
    {
        EditorPanelRegister::GetInstance().Register(EditorPanelIds::Console, CreateConsolePanel);
    }

    const char* QtConsolePanel::GetPanelId() const
    {
        return EditorPanelIds::Console;
    }

    void* QtConsolePanel::GetNativeView() const
    {
        return const_cast<QWidget*>(static_cast<const QWidget*>(this));
    }

    QtConsolePanel::QtConsolePanel(QWidget *parent)
        : QWidget(parent)
        , ui(new Ui::QtConsolePanel)
    {
        ui->setupUi(this);
        // 从 Qt 资源系统加载皮肤样式表（qrc:/Skin/...）
        QString _styleSheet = QtHelper::ReadStringFromFile(":/Skin/Skin/Unreal.skin");
        this->setStyleSheet(_styleSheet);   
    }

    QtConsolePanel::~QtConsolePanel()
    {
        delete ui;
    }

    void QtConsolePanel::Show()
    {
        this->show();
    }

    void QtConsolePanel::Hide()
    {
        this->hide();
    }

    void QtConsolePanel::Close()
    {
        this->close();
    }
}