import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0

import "qmluilib/common/Tool.js" as Tool;

import "./views/home"

Window {
    id: mainWndId

    visible: true

    width: Math.floor(Screen.desktopAvailableWidth * 0.8)
    height: Math.floor(Screen.desktopAvailableHeight * 0.8)
    minimumWidth: 800
    minimumHeight: 600

    title: qsTr("慧影音")

    // 页面管理器
    StackView {
        id: stackId

        anchors.fill: parent

        //initialItem: "qrc:/views/home/HomeView.qml"
        onChildrenChanged: {

        }
    }

    Component.onCompleted: {
        Tool.printMsg("main.qml Component.onCompleted.");

        // 初如化页面
        stackId.push(homeViewId);
    }

    Component.onDestruction: {
        //Tool.printMsg("main.qml Component.onDestruction.");
    }

    // 首页
    Loader {
        id: homeViewId

        HomeView {
            mainWnd: mainWndId
        }
    }

}
