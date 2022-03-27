#include "video_control.h"

#include "h2xbase/file/file_util.h"
#include "h2xbase/string/string_util.h"

#include <QJsonObject>
#include <QJsonArray>

namespace h2xplugins {

VideoControl::VideoControl() : inputAvFmtCtx_(nullptr), options_(nullptr),
    inited_(false), running_(false), pauseing_(false) {

    av_log_set_level(AV_LOG_INFO);
}

VideoControl::~VideoControl() {
    this->reset();
}

void VideoControl::setError(int code, QString msg) {
    excep_.setMsg(code, msg);
}

void VideoControl::reset() {
    params_ = QString("");
    param_info_.reset();

    stop();

    // 销毁字典
    if (options_) {
        av_dict_free(&options_);
        options_ = nullptr;
    }

    inited_ = false;
}

//
// OnParseParams : 解析参数
//
bool VideoControl::OnParseParams() {
    // 判断参数是否为空
    if (params_.isEmpty()) {
        QString strErrorMsg("VideoPlayer::OnParseParams param is empty");
        this->setError(-1, strErrorMsg);
        qDebug("%s\n", strErrorMsg.toUtf8().data());
        return false;
    }

    // 解析参数
    QJsonObject paramObj;
    if (!h2xbase::StringUtil::convertQStringToQJsonObject(params_, paramObj)) {
        QString strErrorMsg("VideoPlayer::OnParseParams param is not valid");
        this->setError(-1, strErrorMsg);
        qDebug("%s\n", strErrorMsg.toUtf8().data());
        return false;
    }

    // 判断是否包含文件名字段
    if (!paramObj.contains("fileName")) {
        QString strErrorMsg("VideoPlayer::OnParseParams param error, not contains fileName field.");
        this->setError(-1, strErrorMsg);
        qDebug("%s\n", strErrorMsg.toUtf8().data());
        return false;
    }

    // 获取文件名
    param_info_.fileName = paramObj.value("fileName").toString();
    // 获取文件大小，不存在会返回-1
    param_info_.fileSize = h2xbase::FileUtil::getFileSize(param_info_.fileName);
    param_info_.isExist = param_info_.fileSize >= 0 ? true : false;

    inited_ = true;

    return true;
}

bool VideoControl::OnInputStreamValid() {
    if (!inputAvFmtCtx_) {
        return false;
    }

    int status = avformat_find_stream_info(inputAvFmtCtx_, NULL);

    return status == 0 ? true : false;
}

bool VideoControl::init(QString strJsonParams) {
    qDebug("VideoPlayer::init params, %s\n", strJsonParams.toUtf8().data());

    this->reset();

    // 保存参数
    params_ = strJsonParams;

    // 解析参数
    if (!this->OnParseParams()) {
        qDebug("VideoPlayer::init OnParseParams fail.\n");
        return false;
    }

    // 设置选项
    av_dict_set(&options_, "probesize", "4096", 0);
    av_dict_set(&options_, "video_size", "640x480", 0);
    av_dict_set(&options_, "pixel_format", "rgb24", 0);
    av_dict_set(&options_, "max_delay", "100", 0);  //指定最大延时100毫秒

    return true;
}

//
// start : 启动插件
//
int VideoControl::start() {
    int status = -1;

    // 判断是否已经初始化
    if (!inited_) {
        QString strErrorMsg("VideoPlayer::start not inited");
        this->setError(-1, strErrorMsg);
        qDebug("%s\n", strErrorMsg.toUtf8().data());
        return -1;
    }

    // 分配内存
    inputAvFmtCtx_ = avformat_alloc_context();
    if (!inputAvFmtCtx_) {
        QString strErrorMsg("VideoPlayer::start avformat_alloc_context fail");
        this->setError(-2, strErrorMsg);
        qDebug("%s\n", strErrorMsg.toUtf8().data());
        return -2;
    }

    // 打开输入流
    status = avformat_open_input(&inputAvFmtCtx_, param_info_.fileName.toUtf8().data(), (AVInputFormat*)NULL, &options_);
    if (status != 0) {
        QString strErrorMsg = QString("VideoPlayer::start avformat_open_input fail, code:%1").arg(status);
        this->setError(-3, strErrorMsg);
        qDebug("%s\n", strErrorMsg.toUtf8().data());
        return -3;
    }

    // 判断输入流是否有效
    if (!this->OnInputStreamValid()) {
        QString strErrorMsg("VideoPlayer::start OnInputStreamValid fail");
        this->setError(-4, strErrorMsg);
        qDebug("%s\n", strErrorMsg.toUtf8().data());
        return -4;
    }

    // 打印输入流信息
    av_dump_format(inputAvFmtCtx_, 0, param_info_.fileName.toUtf8().data(), 0);

    running_ = true;

    return 0;
}

void VideoControl::stop() {
    if (inputAvFmtCtx_) {
        avformat_close_input(&inputAvFmtCtx_);
        inputAvFmtCtx_ = NULL;
    }

    if (pauseing_) {
        pauseing_ = false;
    }

    if (running_) {
        running_ = false;
    }
}

bool VideoControl::pause() {
    return false;
}

bool VideoControl::resume() {
    return false;
}

inline bool VideoControl::isInited() {
    return inited_;
}

inline bool VideoControl::isRunning() {
    return running_;
}

inline bool VideoControl::isPause() {
    return pauseing_;
}

void VideoControl::run() {

}

bool VideoControl::getVideoInfo(VideoInfo& info) {
    if (!inputAvFmtCtx_) {
        return false;
    }

    // 查找视频流信息
    int status = avformat_find_stream_info(inputAvFmtCtx_, NULL);
    if (status != 0) {
        return false;
    }

    // 视频流个数
    int streamNum = inputAvFmtCtx_->nb_streams;

    // 视频总秒数
    int secs = inputAvFmtCtx_->duration / 1000000;

    //  比特率
    int bitRates = inputAvFmtCtx_->bit_rate / 1000;

    // 流信息
    AVInputFormat* infoFmt = inputAvFmtCtx_->iformat;

    // 输入流名称
    const char* fmtName = infoFmt->name;

    info.streamNum = streamNum;
    info.secs = secs;
    info.bitRates = bitRates;

    for(int i = 0; i < streamNum; i++) {
        AVStream* inputStream = inputAvFmtCtx_->streams[i];

        if (inputStream->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
            // 判断为视频
        }
        else if (inputStream->codecpar->codec_type == AVMEDIA_TYPE_AUDIO) {
            // 判断为音频
        }
    }

    return true;
}


} // end namespace h2xplugins
