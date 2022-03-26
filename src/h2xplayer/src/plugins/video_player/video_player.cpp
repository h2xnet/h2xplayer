#include "video_player.h"

VideoPlayer::VideoPlayer() {

}

VideoPlayer::~VideoPlayer() {

}

bool VideoPlayer::init(QString strJsonParams) {
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
