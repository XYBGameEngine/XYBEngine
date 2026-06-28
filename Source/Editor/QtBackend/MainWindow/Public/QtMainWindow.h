#ifndef QTMAINWINDOW_H
#define QTMAINWINDOW_H

#include "IEditorWindow.h"
#include <QMainWindow>

namespace Ui {
class QtMainWindow;
}

namespace XYBEngine
{
    class QtMainWindow : public QMainWindow, public IEditorWindow
    {
        Q_OBJECT

    public:
        explicit QtMainWindow(QWidget *parent = nullptr);
        ~QtMainWindow();

        void Show() override;
        
        void Hide() override;

        void Close() override;

    private:
        Ui::QtMainWindow *ui;
    };

    void QtMainWindowResiter();
}


#endif // QTMAINWINDOW_H
