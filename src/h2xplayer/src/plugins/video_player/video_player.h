#ifndef VIDEO_PLAYER_H
#define VIDEO_PLAYER_H

#include "h2xcore/plugin.h"

/*
 * ClassName: VideoPlayer
 * Desc: 视频播放插件
 * Author: zfs
 * Date: 2022-03-26 11:43
 * Comment：
 */
class VideoPlayer : public h2xcore::Plugin {
public:
    VideoPlayer();
    virtual ~VideoPlayer();

    // h2xcore::Plugin
    virtual bool init(QString strJsonParams) override;
    virtual int start() override;
    virtual void stop() override;
    virtual bool pause() override;
    virtual bool resume() override;
    virtual void run() override;
    virtual bool isRunning() override;
    virtual bool isPause() override;
};

#endif // VIDEO_PLAYER_H
