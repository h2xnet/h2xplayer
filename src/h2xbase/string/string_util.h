#ifndef STRING_UTIL_H
#define STRING_UTIL_H

#include "h2xbase/h2xbase_export.h"

#include <QString>
#include <QJsonArray>
#include <QJsonObject>

namespace h2xbase {

/*
 * ClassName: StringUtil
 * Desc: 字符串处理类
 * Author: zfs
 * Date: 2022-03-19 16:58
 */

class H2XBASE_API StringUtil
{
public:
    StringUtil() = delete;
    ~StringUtil() = delete;

    static QString convertQJsonObjectToQString(const QJsonObject& obj);
    static QString convertQJsonArrayToQString(const QJsonArray& arrObj);

    static bool convertQStringToQJsonObject(const QString& src, QJsonObject& obj);
    static bool convertQStringToQJsonArray(const QString& src, QJsonArray& arrObj);

};

} // end namespace h2xbase

#endif // STRING_UTIL_H
