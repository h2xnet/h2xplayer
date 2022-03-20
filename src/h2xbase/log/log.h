#ifndef LOG_H
#define LOG_H

#include "h2xbase/h2xbase_export.h"

#include <QString>

#include <qlogging.h>
#include <QMutex>
#include <QFile>

namespace h2xbase {

/*
 * ClassName: Log
 * Desc: 日志处理类
 * Author: zfs
 * Date: 2022-03-19 16:58
 */
class H2XBASE_API Log {
public:
    Log();
    ~Log();

    /*
     * Function: QtMessageHandler
     * Desc: 消息钩子
     * Author: zfs
     * Date: 2022-03-20 10:54
     */
    static void QtMessageHandler(QtMsgType type, const QMessageLogContext& ctx, const QString& msg);

    /*
     * Function: open
     * Desc: 打开日志
     * Author: zfs
     * Date: 2022-03-19 17:36
     * @path: 日志文件目录
     * @type: 打印的日志消息类型
     */
    static bool open(QString path, QtMsgType type = QtDebugMsg);

    /*
     * Function: close
     * Desc: 关闭日志
     * Author: zfs
     * Date: 2022-03-19 17:36
     */
    static void close();

    /*
     * Function: logCanOutput
     * Desc: 判断日志是否能输出
     * Author: zfs
     * Date: 2022-03-20 11:00
     */
    static bool logCanOutput(QtMsgType msgType);

    static void setMsgType(QtMsgType type);
    static QtMsgType getMsgType();

private:
    /*
     * Function: OnRebuildLog
     * Desc: 重建日志
     * Author: zfs
     * Date: 2022-03-20 11:14
     */
    static bool OnRebuildLog();

    static QMutex* mutex_;
    static QFile* file_;
    static QString file_name_; // 日志文件名
    static double log_file_max_size_; // 日志文件最大大小

    static QtMsgType msg_type_; // 消息类型
    static QString msg_head[5]; // 日志消息类型文本字符串

};

} // end namespace h2xbase

#endif // LOG_H
