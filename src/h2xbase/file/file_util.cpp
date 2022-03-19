#include "file_util.h"

#include <QDir>
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

} // end namespace h2xbase
