import QtQuick 2.0
import QtQuick.Controls 2.12

import "../../../qmluilib/common/GlobalValue.js" as GlobalValue;
import "../../../qmluilib/common/Tool.js" as Tool;

/*
 * ClassName: AboutView
 * Desc: 关于视图
 * Author: zfs
 * Date: 2021-12-26 15:25
 */

Rectangle {
    id: aboutViewId

    anchors.fill: parent

    color: GlobalValue.def_page_background_color_

    Component.onCompleted: {
        Tool.printMsg("AboutView.qml onCompleted.");
    }

    Text {
        text: qsTr("关于页面")
    }

}
