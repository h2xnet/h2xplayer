#include "database_cache.h"

#include "h2xbase/file/file_util.h"

DatabaseCache::DatabaseCache(QString connectName) : is_open_(false), connect_name_(connectName) {

}

DatabaseCache::~DatabaseCache() {

}

void DatabaseCache::setConnectName(QString name) {
    connect_name_ = name;
}

bool DatabaseCache::open(QString fileName, int model) {
    if (isOpen()) {
        qDebug("DatabaseCache::open is opened.\n");
        return true;
    }

    if (fileName.isEmpty()) {
        qDebug("DatabaseCache::open fileName isEmpty.\n");
        return false;
    }

    QMutexLocker lock(&mutex_);

    database_ = QSqlDatabase::database();
    if (!database_.isValid()) {
        database_ = QSqlDatabase::addDatabase("QSQLITE", connect_name_);
        if (!database_.isValid()) {
            qDebug("DatabaseCache::open fail, connectName:%s.\n", connect_name_.toUtf8().data());
            return false;
        }
    }

    // 打开数据库
    qDebug("DatabaseCache::open file: %s\n", fileName.toUtf8().data());
    database_.setDatabaseName(fileName);
    if (!database_.open()) {
        qDebug("DatabaseCache::open file:%s open fail.\n", fileName.toUtf8().data());
        qDebug("DatabaseCache::open open error msg:%s\n", qPrintable(database_.lastError().text()));
        return false;
    }

    qDebug("DatabaseCache::open file %s success.\n", fileName.toUtf8().data());

    is_open_ = true;

    return true;
}

void DatabaseCache::close() {
    if (isOpen()) {
        QMutexLocker lock(&mutex_);
        database_.close();
        is_open_ = false;
    }
}

bool DatabaseCache::isOpen() {
    return false;
}

bool DatabaseCache::write(QString key, QString value) {
    return false;
}

QString DatabaseCache::read(QString key) {
    return QString("");
}

bool DatabaseCache::remove(QString key) {
    return false;
}

bool DatabaseCache::writeAll(QString values) {
    return false;
}

QString DatabaseCache::readAll() {
    return QString("");
}
