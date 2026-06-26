#include "QtConsoleWindow.h"
#include "ui_QtConsoleWindow.h" 

QtConsoleWindow::QtConsoleWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QtConsoleWindow)
{
    ui->setupUi(this); 
    QString _styleSheet = QtHelper::ReadStringFromFile(":/Skin/Skin/Dark02.skin");
    this->setStyleSheet(_styleSheet); 
    XYBEngine::Log::GetInstance().LogWarning("---------------StyleSheet-----------------");
    XYBEngine::Log::GetInstance().LogWarning(_styleSheet.toStdString());
}

QtConsoleWindow::~QtConsoleWindow()
{
    delete ui;
}
