import QtQuick 2.0
import QtQuick.Controls 2.12

import "../../qmluilib/bar"

import "../../qmluilib/common/Tool.js" as Tool
import "../common/ConstData.js" as ConstData

Rectangle {
    id: homeViewId

    property var pageId: "homeViewId"

    anchors.fill: parent

    color: "transparent"

    Component.onCompleted: {
        Tool.printMsg("HomeView.qml Component.onCompleted.");

        // 初始化导航
        let curSelIndex = 0;
        bottomNavId.init(ConstData.getHomeNavDatas(), curSelIndex);
        onNavItemChanged("playListId", curSelIndex, -1);
    }

    // 页面管理器
    StackView {
        id: pageStackId

        anchors.fill: parent

        //initialItem: "qrc:/views/home/play_list/PlayListView.qml"
    }

    // 底部导航区域
    Rectangle {
        id: bottomNavAreaId

        anchors {

            bottom: parent.bottom
            bottomMargin: 50
        }

        width: parent.width
        height: 80
        color: "transparent"

        HorizontalNavigationBar {
            id: bottomNavId

            anchors.centerIn: parent

            onButtonClick: function(newId, newIndex, oldIndex) {
                Tool.printMsg("HomeView.qml HorizontalNavigationBar onButtonClick newId:" + newId + " newIndex:" + newIndex + " oldIndex:" + oldIndex)
                onNavItemChanged(newId, newIndex, oldIndex);
            }

        } // end bottomNavId

    } // end bottomNavAreaId Rectangle

    /*
     * Function: onNavItemChanged
     * Desc: 导航项改变事件
     * Author: zfs
     * Date: 2021-12-26 15:37
     * @id: 导航按钮ID
     * @index: 改变后导航按钮序号
     * @oldIndex: 改变前导航按钮序号
     */
    function onNavItemChanged(id, index, oldIndex = -1) {
        // 首先清空历史页面
        if (pageStackId.depth > 0) {
            pageStackId.clear();
        }

        switch(id) {
        //case "playListId": // 播放列表
        //    break;
        case "playHistoryId": // 排放历史
            pageStackId.push("qrc:/views/home/play_history/PlayHistoryView.qml");
            break;
        case "settingId": // 设置
            pageStackId.push("qrc:/views/home/setting/SettingView.qml");
            break;
        case "aboutId": // 关于
            pageStackId.push("qrc:/views/home/about/AboutView.qml");
            break;
        default:
            pageStackId.push("qrc:/views/home/play_list/PlayListView.qml");
            break;
        }
    }

} // end homeViewId Rectangle
