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
     * Function: open
     * Desc: 打开日志
     * Author: zfs
     * Date: 2022-03-19 17:36
     * @path: 日志文件目录
     */
    static bool open(QString path);

    /*
     * Function: close
     * Desc: 关闭日志
     * Author: zfs
     * Date: 2022-03-19 17:36
     */
    static void close();

private:
    static QMutex mutex_;
    static QFile* file_;
    static QString file_name_; // 日志文件名

    static QtMsgType msg_type_;
    static QString msg_head[5];

};

} // end namespace h2xbase

#endif // LOG_H
