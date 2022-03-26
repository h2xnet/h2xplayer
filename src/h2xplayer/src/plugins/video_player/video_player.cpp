#include "video_player.h"

#include "h2xbase/string/string_util.h"

#include <QJsonObject>
#include <QJsonArray>

namespace h2xplugins {

VideoPlayer::VideoPlayer() : inputAvFmtCtx_(nullptr), options_(nullptr) {
    av_log_set_level(AV_LOG_INFO);
}

VideoPlayer::~VideoPlayer() {

}

void VideoPlayer::reset() {

}

bool VideoPlayer::init(QString strJsonParams) {
    this->reset();

    av_dict_set(&options_, "probesize", "4096", 0);
    av_dict_set(&options_, "video_size", "640x480", 0);
    av_dict_set(&options_, "pixel_format", "rgb24", 0);
    av_dict_set(&options_, "max_delay", "100", 0);  //指定最大延时100毫秒

    return true;
}

int VideoPlayer::start() {
    return 0;
}

void VideoPlayer::stop() {
}

bool VideoPlayer::pause() {
    return false;
}

bool VideoPlayer::resume() {
    return false;
}

bool VideoPlayer::isRunning() {
    return false;
}

bool VideoPlayer::isPause() {
    return false;
}

void VideoPlayer::run() {

}

} // end namespace h2xplugins
