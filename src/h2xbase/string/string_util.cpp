#include "string_util.h"

#include <QJsonDocument>

namespace h2xbase {

QString StringUtil::convertQJsonObjectToQString(const QJsonObject& obj) {
    return QString(QJsonDocument(obj).toJson(QJsonDocument::Compact));
}

QString StringUtil::convertQJsonArrayToQString(const QJsonArray& arrObj) {
    return QString(QJsonDocument(arrObj).toJson(QJsonDocument::Compact));
}

bool StringUtil::convertQStringToQJsonObject(const QString& src, QJsonObject& obj) {
    QJsonDocument doc = QJsonDocument::fromJson(src.toUtf8());
    if (!doc.isNull() && doc.isObject()) {
        obj = doc.object();
        return true;
    }
    return false;
}

bool StringUtil::convertQStringToQJsonArray(const QString& src, QJsonArray& arrObj) {
    QJsonDocument doc = QJsonDocument::fromJson(src.toUtf8());
    if (!doc.isNull() && doc.isArray()) {
        arrObj = doc.array();
        return true;
    }
    return false;
}

} // end namespace h2xbase
