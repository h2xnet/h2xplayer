#ifndef VIDEO_PLAYER_H
#define VIDEO_PLAYER_H

#include <QQuickPaintedItem>
#include <QImage>
#include <QObject>

namespace h2xplugins {

/*
 * ClassName: VideoPlayer
 * Desc: 视频播放插件
 * Author: zfs
 * Date: 2022-03-26 11:43
 * Comment：
 */
class VideoPlayer : public QQuickPaintedItem {
    Q_OBJECT
public:
    explicit VideoPlayer();
    virtual ~VideoPlayer();

    /*
     * Function: start
     * Desc: 开始播放
     * Author: zfs
     * Date: 2022-03-27 11:06
     */
    Q_INVOKABLE int start(QString options);

    /*
     * Function: pause
     * Desc: 暂停播放
     * Author: zfs
     * Date: 2022-03-27 11:06
     */
    Q_INVOKABLE int pause();

    /*
     * Function: pause
     * Desc: 继续播放
     * Author: zfs
     * Date: 2022-03-27 11:06
     */
    Q_INVOKABLE int resume();

    /*
     * Function: stop
     * Desc: 停止播放
     * Author: zfs
     * Date: 2022-03-27 11:06
     */
    Q_INVOKABLE int stop();

protected:
    virtual void paint(QPainter *pPainter);

private:

    QImage frame_;

};

} // end namespace h2xplugins

#endif // VIDEO_PLAYER_H
