#include "log.h"

#include "h2xbase/file/file_util.h"

#include <QDateTime>
#include <QTextStream>

namespace h2xbase {

QFile* Log::file_ = nullptr;
QMutex* Log::mutex_ = nullptr;
QString Log::file_name_ = QString("");
QtMsgType Log::msg_type_ = QtMsgType::QtInfoMsg;
double Log::log_file_max_size_ = 500; // 500M

QString Log::msg_head[] = {
    QString("Debug - "),
    QString("Warning - "),
    QString("Critical - "),
    QString("Fatal - "),
    QString("Info - ")
};

void Log::QtMessageHandler(QtMsgType type, const QMessageLogContext& ctx, const QString& msg) {
    if (!logCanOutput(type)) {
        return;
    }

    QByteArray localMsg = msg.toUtf8();
    QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.ddd");

    if (file_) {
        QMutexLocker lock(mutex_);

        double fileSize = file_->size();
        if (fileSize > log_file_max_size_) {
            file_->close();
            delete file_;
            file_ = nullptr;

            if (!OnRebuildLog()) {
                qDebug("log.cpp QtMessageHandler OnRebuildLog fail.\n");
                return;
            }
        }

        QTextStream tWrite(file_);
        QString msgText="%1 | %5 | %2:%3 | %4\n";
        msgText = msgText.arg(msg_head[type].toStdString().data()).arg(ctx.file).arg(ctx.line).arg(localMsg.constData()).arg(current_date_time);
        tWrite << msgText;
    }
    else {
        fprintf(stderr, "%s | %s | %s:%u | %s\n", msg_head[type].toStdString().data(), current_date_time.toLocal8Bit().constData(), ctx.file, ctx.line, localMsg.constData());
    }

}

Log::Log() {
    mutex_ = new QMutex();
}

Log::~Log() {
    close();

    delete mutex_;
    mutex_ = nullptr;
}

//
// open : 打开日志
//
bool Log::open(QString fileName, QtMsgType type) {
    if (file_) {
        return true;
    }

    QMutexLocker lock(mutex_);
    file_name_ = fileName;
    msg_type_ = type;

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

        delete file_;
        file_ = nullptr;
        return false;
    }

    // 安装消息钩子
    qInstallMessageHandler(Log::QtMessageHandler);

    return true;
}

//
// close : 关闭日志
//
void Log::close() {
    if (file_) {
        QMutexLocker lock(mutex_);

        file_->close();
        delete file_;
        file_ = nullptr;
    }
}

//
// OnRebuildLog : 重建日志
//
bool Log::OnRebuildLog() {
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

        delete file_;
        file_ = nullptr;
        return false;
    }

    // 安装消息钩子
    qInstallMessageHandler(Log::QtMessageHandler);

    return true;
}

//
// logCanOutput : 判断日志是否能输出
//
bool Log::logCanOutput(QtMsgType msgType) {
    return (msg_type_ <= msgType ? true : false);
}

void Log::setMsgType(QtMsgType type) {
    msg_type_ = type;
}

QtMsgType Log::getMsgType() {
    return msg_type_;
}

}
