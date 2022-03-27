#ifndef VIDEO_THREAD_H
#define VIDEO_THREAD_H

#include <QThread>

namespace h2xplugins {

/*
 * ClassName: VideoThread
 * Desc: 视频播放线程
 * Author: zfs
 * Date: 2022-03-27 10:2
 * Comment：
 */

class VideoThread : public QThread {
    Q_OBJECT
public:
    VideoThread();
    virtual ~VideoThread();

};

} // end namespace h2xplugins

#endif // VIDEO_THREAD_H
