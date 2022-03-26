#ifndef DATABASE_CACHE_H
#define DATABASE_CACHE_H

#include "h2xcore/cache.h"

#include <QMutex>
#include <qsqldatabase.h>
#include <qsqlerror.h>

/*
 * ClassName: DatabaseCache
 * Desc: 数据库缓存
 * Author: zfs
 * Date: 2022-03-20 12:04
 * Comment：数据库缓存主要用sqlite存储，key代表存储数据的数据库表名称，value代表字段对应的值列表
 */

class DatabaseCache : public h2xcore::Cache
{
public:
    DatabaseCache(QString connectName = QString("h2xplayerSqlite"));
    virtual ~DatabaseCache();

    virtual bool open(QString fileName, int model) override;
    virtual void close() override;

    virtual bool isOpen() override;

    virtual bool write(QString key, QString value) override;
    virtual QString read(QString key) override;
    virtual bool remove(QString key) override;

    virtual bool writeAll(QString values) override;
    virtual QString readAll() override;

    void setConnectName(QString name);

private:
    bool is_open_;

    QMutex mutex_;
    QSqlDatabase database_;

    QString connect_name_; // 连接名
};

#endif // DATABASE_CACHE_H
