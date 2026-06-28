// Copyright XYBEngine. All Rights Reserved.
//
// QtConsoleWindow.cpp - 控制台 Qt 控件实现

#include "QtConsoleWindow.h"
#include "ui_QtConsoleWindow.h" 
#include "QtHelper.h" 
 
void QtConsoleWindowResiter()
{
    EditorWindowFactory::GetInstance().Register(EditorWindowType::ConsoleWindow, MakeShared<QtConsoleWindow>());
}

QtConsoleWindow::QtConsoleWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QtConsoleWindow)
{
    ui->setupUi(this);
    // 从 Qt 资源系统加载皮肤样式表（qrc:/Skin/...）
    QString _styleSheet = QtHelper::ReadStringFromFile(":/Skin/Skin/Unreal.skin");
    this->setStyleSheet(_styleSheet);   
}

QtConsoleWindow::~QtConsoleWindow()
{
    delete ui;
}

void QtConsoleWindow::Show()
{
    this->show();
}

void QtConsoleWindow::Hide()
{
    this->hide();
}

void QtConsoleWindow::Close()
{
    this->close();
}