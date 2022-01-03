import QtQuick 2.0
import QtQuick.Controls 2.12

import "../../../qmluilib/list"
import "../../../qmluilib/common/GlobalValue.js" as GlobalValue;
import "../../../qmluilib/common/Tool.js" as Tool;

import "../../common/ConstData.js" as ConstData;

/*
 * ClassName: PlayListView
 * Desc: 播放列表视图
 * Author: zfs
 * Date: 2021-12-26 15:21
 */

Rectangle {
    id: playListViewId

    property int padLeft: 20
    property int padTop: 100
    property int padRight: 20
    property int padBottom: 180

    // 列表宽
    property int listWidth: 900

    anchors.fill: parent

    color: GlobalValue.def_page_background_color_

    Component.onCompleted: {
        Tool.printMsg("PlayListView.qml onCompleted.");

        // test data
        let datas = ConstData.getPlayListTestDatas();
        onUpdateListData(datas);

    }

    //
    // onUpdateListData : 更新列表数据
    //
    function onUpdateListData(list) {
        listId.init(list);
    }

    // 列表
    CardList {
        id: listId

        anchors {
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            topMargin: playListViewId.padTop
        }

        showVerticalScrollBar: false
        width: listWidth
        height: parent.height - playListViewId.padTop - playListViewId.padBottom

    } // end CardList

} // end playListViewId Rectangle
