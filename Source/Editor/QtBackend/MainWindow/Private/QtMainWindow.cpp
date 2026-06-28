#include "QtMainWindow.h"
#include "ui_QtMainWindow.h"
#include "QtHelper.h"

QtMainWindow::QtMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QtMainWindow)
{
    ui->setupUi(this);
    // 从 Qt 资源系统加载皮肤样式表（qrc:/Skin/...）
    QString _styleSheet = QtHelper::ReadStringFromFile(":/Skin/Skin/Unreal.skin");
    this->setStyleSheet(_styleSheet);   
}

QtMainWindow::~QtMainWindow()
{
    delete ui;
}

void QtMainWindow::Show()
{
    this->show();
}

void QtMainWindow::Hide()
{
    this->hide();
}

void QtMainWindow::Close()
{
    this->close();
}

void QtMainWindowResiter()
{
    EditorWindowFactory::GetInstance().Register(EditorWindowType::MainWindow, MakeShared<QtMainWindow>());
}