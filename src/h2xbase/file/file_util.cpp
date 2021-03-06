#include "file_util.h"

#include <QDir>
#include <QFile>
#include <QStandardPaths>
#include <QCoreApplication>

namespace h2xbase {

//
// getAppPath : 获取应用路径
//
QString FileUtil::getAppPath() {
    return QCoreApplication::applicationDirPath();
}

//
// GetAppDataPath : 获取应用缓存路径
//
QString FileUtil::getAppDataPath() {
    return QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
}

//
// pathIsExist : 判断路径是否存在
//
bool FileUtil::pathIsExist(QString path, bool create) {
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
// getFileSize : 获取文件大小
//
qint64 FileUtil::getFileSize(const QString& fileName) {
    QFileInfo info(fileName);
    if (info.exists()) {
        return info.size();
    }
    return -1;
}

//
// readFileAll : 读取文件内容
//
QString FileUtil::readFileAll(const QString& fileName) {
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
// writeFile : 写文件
//
int FileUtil::writeFile(const QString& fileName, const QString& data) {
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
