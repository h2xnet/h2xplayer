#ifndef PLUGIN_H
#define PLUGIN_H

#include "h2xcore/h2xcore_export.h"

#include <QString>

namespace h2xcore {

/*
 * ClassName: Plugin
 * Desc: 插件基类，原则上一个插件对应一个运行子线程，由插件管理器负责调度
 * Author: zfs
 * Date: 2022-03-26 10:00
 */

class H2XCORE_API Plugin
{
public:
    Plugin();
    virtual ~Plugin();

    /*
     * Function: init
     * Desc: 初始化插件
     * Author: zfs
     * Date: 2022-03-26 10:09
     * @strJsonParams: JSON格式字符串参数
     */
    virtual bool init(QString strJsonParams) = 0;

    /*
     * Function: start
     * Desc: 启动插件
     * Author: zfs
     * Date: 2022-03-26 10:10
     */
    virtual int start() = 0;

    /*
     * Function: stop
     * Desc: 停止插件运行
     * Author: zfs
     * Date: 2022-03-26 10:10
     */
    virtual void stop() = 0;

    /*
     * Function: pause
     * Desc: 暂停插件运行
     * Author: zfs
     * Date: 2022-03-26 10:10
     */
    virtual bool pause() = 0;

    /*
     * Function: resume
     * Desc: 恢复暂停的插件运行
     * Author: zfs
     * Date: 2022-03-26 10:10
     */
    virtual bool resume() = 0;

    /*
     * Function: run
     * Desc: 插件主体运行函数，由start触发
     * Author: zfs
     * Date: 2022-03-26 10:09
     */
    virtual void run() = 0;

    /*
     * Function: isRunning
     * Desc: 判断插件运行状态
     * Author: zfs
     * Date: 2022-03-26 10:11
     */
    virtual bool isRunning() = 0;

    /*
     * Function: isPause
     * Desc: 判断是否处于暂停状态
     * Author: zfs
     * Date: 2022-03-26 10:11
     */
    virtual bool isPause() = 0;

};

} // end namespace h2xcore

#endif // PLUGIN_H
