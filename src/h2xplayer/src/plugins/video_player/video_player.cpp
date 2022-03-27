#include "video_player.h"

#include "h2xbase/file/file_util.h"
#include "h2xbase/string/string_util.h"

#include <QPainter>
#include <QJsonObject>
#include <QJsonArray>

namespace h2xplugins {

VideoPlayer::VideoPlayer() {

}

VideoPlayer::~VideoPlayer() {

}

void VideoPlayer::paint(QPainter *pPainter) {
    if (!frame_.isNull()) {
        pPainter->drawImage(QRect(0, 0, width(), height()), frame_);
    }
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
