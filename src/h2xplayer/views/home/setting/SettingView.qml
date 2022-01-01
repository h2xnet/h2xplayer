import QtQuick 2.0
import QtQuick.Controls 2.12

import "../../../qmluilib/common/GlobalValue.js" as GlobalValue;
import "../../../qmluilib/common/Tool.js" as Tool;

/*
 * ClassName: SettingView
 * Desc: 设置视图
 * Author: zfs
 * Date: 2021-12-26 15:24
 */

Rectangle {
    id: settingViewId

    anchors.fill: parent

    color: GlobalValue.def_page_background_color_

    Component.onCompleted: {
        Tool.printMsg("SettingView.qml onCompleted.");
    }

    Text {
        text: qsTr("设置页面")
    }

}
