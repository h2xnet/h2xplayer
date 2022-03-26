#ifndef FILE_CACHE_H
#define FILE_CACHE_H

#include "h2xcore/cache.h"

#include <QMutex>
#include <qsqldatabase.h>
#include <qsqlerror.h>

/*
 * ClassName: FileCache
 * Desc: 文件缓存
 * Author: zfs
 * Date: 2022-03-26 11:29
 * Comment：文件缓存主要用文件来存储JSON字符串，主要用于配置数据的存储
 */

class FileCache  : public h2xcore::Cache {
public:
    FileCache();
    virtual ~FileCache();

    virtual bool open(QString fileName, int model) override;
    virtual void close() override;

    virtual bool isOpen() override;

    virtual bool write(QString key, QString value) override;
    virtual QString read(QString key) override;
    virtual bool remove(QString key) override;

    virtual bool writeAll(QString values) override;
    virtual QString readAll() override;

};

#endif // FILE_CACHE_H
