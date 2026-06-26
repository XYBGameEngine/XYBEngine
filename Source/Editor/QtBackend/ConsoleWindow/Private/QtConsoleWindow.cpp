#include "QtConsoleWindow.h"
#include "ui_QtConsoleWindow.h" 

QtConsoleWindow::QtConsoleWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QtConsoleWindow)
{
    ui->setupUi(this); 
    QString _styleSheet = QtHelper::ReadStringFromFile(":/Skin/Skin/Dark02.skin");
    this->setStyleSheet(_styleSheet); 
    XYB_LOG_WARNING("---------------StyleSheet-----------------");
    XYB_LOG_WARNING(_styleSheet.toStdString());
}

QtConsoleWindow::~QtConsoleWindow()
{
    delete ui;
}
