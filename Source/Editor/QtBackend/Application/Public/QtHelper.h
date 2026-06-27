// Copyright XYBEngine. All Rights Reserved.
//
// QtHelper.h - Qt 通用工具函数
//
// 模块：Editor / QtBackend

#ifndef QTHELPER_H
#define QTHELPER_H

#include <QWidget>
#include <QFile> 

/** Qt 侧静态工具，供各 Qt 控件复用 */
class QtHelper
{
    public:  
    /** 从本地路径或 qrc 资源路径读取文本内容，失败返回空 QString */
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