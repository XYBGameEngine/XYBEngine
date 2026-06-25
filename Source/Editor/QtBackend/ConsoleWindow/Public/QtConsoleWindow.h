#ifndef QTCONSOLEWINDOW_H
#define QTCONSOLEWINDOW_H

#include <QWidget>

namespace Ui {
class QtConsoleWindow;
}

class QtConsoleWindow : public QWidget
{
    Q_OBJECT

public:
    explicit QtConsoleWindow(QWidget *parent = nullptr);
    ~QtConsoleWindow();

private:
    Ui::QtConsoleWindow *ui;
};

#endif // QTCONSOLEWINDOW_H
