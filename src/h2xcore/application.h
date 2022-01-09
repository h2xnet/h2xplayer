#ifndef APPLICATION_H
#define APPLICATION_H

#include "h2xcore/h2xcore_export.h"

/*
 * ClassName: Application
 * Desc: 应用类基类
 * Author: zfs
 * Date: 2022-01-09 14:39
 */

namespace h2xcore {


class H2XCORE_API Application {
public:
    Application();
    virtual ~Application();

    virtual bool initApp() = 0;
};

} // end namespace h2xcore

#endif // APPLICATION_H
