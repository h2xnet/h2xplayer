import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Window 2.12

import h2xplayer.plugin.pc 1.0

/*
 * ClassName: VideoPlayerWnd
 * Desc: 视频播放器插件窗口
 * Author: zfs
 * Date: 2022-03-27 11:16
 */
Window {
    id: controllerId

    property int borderRadius: 4
    property var backColor: "#000000"   // 背景颜色

    function beginShow() {
        controllerId.show();
    }

    function endShow() {
        controllerId.close();
    }

    width: 800
    height: 400
    color: "transparent"

    // 背景窗口
    Rectangle {
        id: backWndId

        anchors.fill: parent

        radius: borderRadius
        color: backColor

    } // end backWndId Rectangle

    // 播放窗口
    Rectangle {
        id: playerWndId

        anchors.centerIn: parent

        width: parent.width - 10
        height: parent.height - 10
        color: "transparent"

        // 视频播放控制器
        VideoPlayer {
            id: videoPlayerId

        }

    } // end playerWndId Rectangle

} // end controllerId Item
