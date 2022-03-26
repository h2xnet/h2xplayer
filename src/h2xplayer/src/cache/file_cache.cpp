#include "file_cache.h"

FileCache::FileCache() {

}

FileCache::~FileCache() {

}

bool FileCache::open(QString fileName, int model) {
    return false;
}

void FileCache::close() {

}

bool FileCache::isOpen() {
    return false;
}

bool FileCache::write(QString key, QString value) {
    return true;
}

QString FileCache::read(QString key) {
    return QString("");
}

bool FileCache::remove(QString key) {
    return false;
}

bool FileCache::writeAll(QString values) {
    return false;
}

QString FileCache::readAll() {
    return QString("");
}
