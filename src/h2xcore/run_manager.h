#ifndef RUN_MANAGER_H
#define RUN_MANAGER_H

#include "h2xcore/h2xcore_export.h"

#include <QString>

namespace h2xcore {

/*
 * ClassName: RunManager
 * Desc: 运行管理器类
 * Author: zfs
 * Date: 2022-03-26 11:02
 */

class H2XCORE_API RunManager
{
public:
    RunManager();
    virtual ~RunManager();

    /*
     * Function: init
     * Desc: 初始化运行
     * Author: zfs
     * Date: 2022-03-26 11:40
     */
    virtual bool init() = 0;
};

} // end namespace h2xcore

#endif // RUN_MANAGER_H
