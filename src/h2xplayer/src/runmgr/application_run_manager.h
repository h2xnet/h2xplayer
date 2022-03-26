#ifndef APPLICATION_RUN_MANAGER_H
#define APPLICATION_RUN_MANAGER_H

#include "h2xcore/run_manager.h"

/*
 * ClassName: ApplicationRunManager
 * Desc: 应用运行管理类
 * Author: zfs
 * Date: 2022-03-26 11:12
 */
class ApplicationRunManager : public h2xcore::RunManager {
public:
    ApplicationRunManager();
    virtual ~ApplicationRunManager();

    // h2xcore::RunManager
    virtual bool init() override;

};

#endif // APPLICATION_RUN_MANAGER_H
