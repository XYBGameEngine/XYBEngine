#ifndef QTHELPER_H
#define QTHELPER_H

#include <QWidget>
#include <QFile> 

namespace XYBEngine
{
    class QtHelper
    {
        public:

        static void SetStyleSheet(QWidget *widget, const QString &url)
        {
            QFile file(url);
            if (file.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QTextStream in(&file);
                widget->setStyleSheet(in.readAll());
            }
            else
            {
                //XYB_ERROR("Failed to open style sheet file: {}", url);
            }
            file.close();
            return;
        }
    };
}

#endif // QTHELPER_H