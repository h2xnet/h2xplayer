#ifndef LOADER_H
#define LOADER_H

#include "h2xcore/h2xcore_export.h"

#include <QString>

namespace h2xcore {

/*
 * ClassName: Loader
 * Desc: 加载器基类
 * Author: zfs
 * Date: 2022-03-26 10:58
 */

class H2XCORE_API Loader {
public:
    Loader();
    virtual ~Loader();

};

} // end namespace h2xcore

#endif // LOADER_H
