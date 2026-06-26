#ifndef QTHELPER_H
#define QTHELPER_H

#include <QWidget>
#include <QFile> 

class QtHelper
{
    public:  
    static QString ReadStringFromFile(const QString &url)
    {
        QFile file(url);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            return file.readAll();
        }
        file.close();
        return QString();
    }
};


#endif // QTHELPER_H