#include "video_player.h"

#include "h2xbase/file/file_util.h"
#include "h2xbase/string/string_util.h"

#include <QJsonObject>
#include <QJsonArray>

namespace h2xplugins {

QObject* VideoPlayer::root_object_ = nullptr;

QObject* VideoPlayer::getQObject() {
    return root_object_;
}

void VideoPlayer::setQObject(QObject* obj) {
    root_object_ = obj;
}

VideoPlayer::VideoPlayer() {

}

VideoPlayer::~VideoPlayer() {

}

void VideoPlayer::paint(QPainter *pPainter) {

}

int VideoPlayer::start(QString options) {
    return 0;
}

int VideoPlayer::pause() {
    return 0;
}

int VideoPlayer::resume() {
    return 0;
}

int VideoPlayer::stop() {
    return 0;
}

} // end namespace h2xplugins
