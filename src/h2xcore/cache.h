#ifndef H2XCORE_CACHE_H
#define H2XCORE_CACHE_H

#include "h2xcore/h2xcore_export.h"

#include <QString>

namespace h2xcore {

/*
 * ClassName: Cache
 * Desc: 缓存类基类
 * Author: zfs
 * Date: 2022-03-20 11:53
 */

class H2XCORE_API Cache {
public:
    Cache();
    virtual ~Cache();

    virtual bool open(QString fileName, int model) = 0;
    virtual void close() = 0;

    virtual bool isOpen() = 0;

    virtual bool write(QString key, QString value) = 0;
    virtual QString read(QString key) = 0;
    virtual bool remove(QString key) = 0;

};

} // end namespace h2xcore

#endif // H2XCORE_CACHE_H
