#include "log.h"

#include "h2xbase/file/file_util.h"

#include <QDateTime>

namespace h2xbase {

QFile* Log::file_ = nullptr;
QString Log::file_name_ = QString("");
QtMsgType Log::msg_type_ = QtInfoMsg;

QString Log::msg_head[] = {
    QString("Debug - "),
    QString("Warning - "),
    QString("Critical - "),
    QString("Fatal - "),
    QString("Info - ")
};

Log::Log() {

}

Log::~Log() {

}

//
// open : 打开日志
//
bool Log::open(QString fileName) {
    QMutexLocker lock(&mutex_);
    file_name_ = fileName;

    // 日志路径
    QString logPath = FileUtil::GetAppPath();

    logPath += QString("/log/"); // 增加log文件夹

    // 判断路径是否存在
    if (!FileUtil::PathIsExist(logPath, true)) {
        qDebug("Log::open logPath: %s is not exists.\n", logPath.toUtf8().data());
        return false;
    }

    QDateTime currentTime = QDateTime::currentDateTime();//yyyy.MM.dd hh:mm:ss.zzz ddd
    QString currentTimeStr =currentTime .toString("yyyy-MM-dd-hh-mm-ss");

    QString logFileName = logPath + currentTimeStr + file_name_;
    file_ = new QFile(logFileName);

    if (!file_->open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)){
        QString errmsg = file_->errorString();
        qDebug("Log::open file open fail. errmsg: %s\n", errmsg.toUtf8().data());
        return false;
    }

    return true;
}

//
// close : 关闭日志
//
void Log::close() {

}

}
