#include "QtConsoleWindow.h"
#include "ui_QtConsoleWindow.h"

QtConsoleWindow::QtConsoleWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QtConsoleWindow)
{
    ui->setupUi(this); 
    QtHelper::SetStyleSheet(this, ":/Skin/Dark.skin");
}

QtConsoleWindow::~QtConsoleWindow()
{
    delete ui;
}
