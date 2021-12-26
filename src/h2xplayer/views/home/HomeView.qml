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
        bottomNavId.init(ConstData.getHomeNavDatas());
    }

    // 底部导航区域
    Rectangle {
        id: bottomNavAreaId

        anchors {

            bottom: parent.bottom
            bottomMargin: 100
        }

        width: parent.width
        height: 100
        color: "transparent"

        HorizontalNavigationBar {
            id: bottomNavId

            anchors.centerIn: parent

            onButtonClick: function(id, navIndex) {
                Tool.printMsg("HomeView.qml HorizontalNavigationBar onButtonClick id:" + id + " index:" + navIndex)
            }

        } // end bottomNavId

    } // end bottomNavAreaId Rectangle

} // end homeViewId Rectangle
