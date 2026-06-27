#include "QtConsoleWindow.h"
#include "ui_QtConsoleWindow.h" 

QtConsoleWindow::QtConsoleWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QtConsoleWindow)
{
    ui->setupUi(this); 
    QString _styleSheet = QtHelper::ReadStringFromFile(":/Skin/Skin/CustomSkin.skin");
    this->setStyleSheet(_styleSheet);   
}

QtConsoleWindow::~QtConsoleWindow()
{
    delete ui;
}
