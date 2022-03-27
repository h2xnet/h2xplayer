#ifndef VIDEO_CONTROL_H
#define VIDEO_CONTROL_H

#include "h2xbase/excep/excep.h"
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
 * ClassName: VideoControl
 * Desc: 视频播放插件
 * Author: zfs
 * Date: 2022-03-26 11:43
 * Comment：
 */
class VideoControl : public h2xcore::Plugin {
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

    //
    // param_info_ : 初始化参数信息
    //
    typedef struct param_info_ {
        param_info_() {
            fileSize = 0;
            isExist = false;
        }

        void reset() {
            fileName = QString("");

            fileSize = 0;
            isExist = false;
        }

        QString fileName; // 文件名
        qint64 fileSize; // 文件大小
        bool isExist; // 文件是否存在标志
    } ParamInfo;

    VideoControl();
    virtual ~VideoControl();

    // h2xcore::Plugin
    virtual void reset() override;
    virtual bool init(QString strJsonParams) override;
    virtual int start() override;
    virtual void stop() override;
    virtual bool pause() override;
    virtual bool resume() override;
    virtual void run() override;
    virtual bool isInited() override;
    virtual bool isRunning() override;
    virtual bool isPause() override;

    void setError(int code, QString msg);

    AVFormatContext* getInputAvFormatContext() const {
            return inputAvFmtCtx_;
        }

    /*
     * FunctionName: getVideoInfo
     * Desc: 获取视频信息
     * Author: fushou
     * Date: 2022-03-26 20:49
     */
    bool getVideoInfo(VideoInfo& info);

private:
    //
    // OnParseParams : 解析参数
    //
    bool OnParseParams();

    /*
     * FunctionName: OnInputStreamValid
     * Description: 判断输入流是否有效
     * Author: fushou
     * Date: 2022-03-26 20:23
     * 返回值：有效返回true，否则返回false
     */
    bool OnInputStreamValid();

    bool inited_;
    bool running_;
    bool pauseing_;

    // 输入格式指针
    AVFormatContext* inputAvFmtCtx_;

    // 输入选项,可用于配置参数
    AVDictionary* options_;

    // 错误消息
    h2xbase::Excep excep_;

    // 初始化参数
    QString params_;
    ParamInfo param_info_;

};

} // end namespace h2xplugins


#endif // VIDEO_CONTROL_H
