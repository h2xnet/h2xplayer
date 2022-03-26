#include "file_util.h"

#include <QDir>
#include <QFile>
#include <QStandardPaths>
#include <QCoreApplication>

namespace h2xbase {

//
// GetAppPath : 获取应用路径
//
QString FileUtil::GetAppPath() {
    return QCoreApplication::applicationDirPath();
}

//
// GetAppDataPath : 获取应用缓存路径
//
QString FileUtil::GetAppDataPath() {
    return QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
}

//
// PathIsExist : 判断路径是否存在
//
bool FileUtil::PathIsExist(QString path, bool create) {
    if (path.isEmpty()) {
        return true;
    }

    QDir qd;
    qd.setPath(path);
    if (!qd.exists()) {
        if (create) {
            qd.mkpath(path);
        }
    }

    return qd.exists();
}

//
// ReadFileAll : 读取文件内容
//
QString FileUtil::ReadFileAll(const QString& fileName) {
    if (fileName.isEmpty()) {
        return QString("");
    }

    QString strResult("");

    QFile f(fileName);
    if (f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        strResult = f.readAll();
        f.close();
    }

    return strResult;
}

//
// WriteFile : 写文件
//
int FileUtil::WriteFile(const QString& fileName, const QString& data) {
    if (fileName.isEmpty()) {
        return -1;
    }

    qint64 ret = 0;
    QFile f(fileName);
    if (f.open(QIODevice::WriteOnly | QIODevice::Text)) {
        if (!data.isEmpty()) {
           ret = f.write(data.toUtf8().data(), data.toUtf8().size());
        }
        f.close();
    }

    if (data.isEmpty()) {
        return 0;
    }

    return ret > 0 ? 0 : -2;
}

} // end namespace h2xbase
