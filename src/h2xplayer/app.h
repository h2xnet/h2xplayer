#ifndef APP_H
#define APP_H

#include "h2xcore/application.h"

/*
 * ClassName: App
 * Desc: 应用类，一个应用程序只能拥有一个应用类，主要完成一些全局功能
 * Author: zfs
 * Date: 2022-01-09 14:39
 */

class App : public h2xcore::Application {
public:
    App();
    ~App();

    virtual bool initApp() override;

    void exitApp();
};

/*
 * Function: GetApp
 * Desc: 获取应用对象
 * Author: zfs
 * Date: 2022-01-09 14:42
 */
extern App& GetApp();

#endif // APP_H
