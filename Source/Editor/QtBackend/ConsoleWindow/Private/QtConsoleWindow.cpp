#include "QtConsoleWindow.h"
#include "ui_QtConsoleWindow.h" 
#include "Log.h"

QtConsoleWindow::QtConsoleWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QtConsoleWindow)
{
    ui->setupUi(this); 
    QString _styleSheet = QtHelper::ReadStringFromFile(":/Skin/Skin/Unreal.skin");
    this->setStyleSheet(_styleSheet);   
}

QtConsoleWindow::~QtConsoleWindow()
{
    delete ui;
}
