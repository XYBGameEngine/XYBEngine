#include "QtConsoleWindow.h"
#include "ui_QtConsoleWindow.h"

QtConsoleWindow::QtConsoleWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QtConsoleWindow)
{
    ui->setupUi(this);
}

QtConsoleWindow::~QtConsoleWindow()
{
    delete ui;
}
