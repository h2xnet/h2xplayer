#ifndef VIDEO_PLAYER_H
#define VIDEO_PLAYER_H

#include "h2xcore/plugin.h"

#if defined (__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libavutil/timestamp.h"
#include "libavutil/time.h"

#if defined (__cplusplus) || defined(c_plusplus)
}
#endif

namespace h2xplugins {


/*
 * ClassName: VideoPlayer
 * Desc: 视频播放插件
 * Author: zfs
 * Date: 2022-03-26 11:43
 * Comment：
 */
class VideoPlayer : public h2xcore::Plugin {
public:
    // video_info_ : 视频流信息
    typedef struct video_info_ {
        video_info_() {
            streamNum = 0;
            secs = 0;
            bitRates = 0;
        }

        int streamNum;  //流个数
        int secs;   // 总秒数
        int bitRates;    // 比特率
    } VideoInfo;

    VideoPlayer();
    virtual ~VideoPlayer();

    // h2xcore::Plugin
    virtual void reset() override;
    virtual bool init(QString strJsonParams) override;
    virtual int start() override;
    virtual void stop() override;
    virtual bool pause() override;
    virtual bool resume() override;
    virtual void run() override;
    virtual bool isRunning() override;
    virtual bool isPause() override;

private:
    // 输入格式指针
    AVFormatContext* inputAvFmtCtx_;

    // 输入选项,可用于配置参数
    AVDictionary* options_;

};

} // end namespace h2xplugins

#endif // VIDEO_PLAYER_H
