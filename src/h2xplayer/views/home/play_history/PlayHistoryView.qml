import QtQuick 2.0
import QtQuick.Controls 2.12

import "../../../qmluilib/list"

import "../../../qmluilib/common/GlobalValue.js" as GlobalValue;
import "../../../qmluilib/common/Tool.js" as Tool;

import "../../common/ConstData.js" as ConstData;

/*
 * ClassName: PlayHistoryView
 * Desc: 播放历史视图
 * Author: zfs
 * Date: 2021-12-26 15:22
 */

Rectangle {
    id: playHistoryViewId

    property int padLeft: 20
    property int padTop: 100
    property int padRight: 20
    property int padBottom: 180

    // 列表宽
    property int listWidth: 1020

    anchors.fill: parent

    color: GlobalValue.def_page_background_color_

    Component.onCompleted: {
        Tool.printMsg("PlayHistoryView.qml onCompleted.");
        // test data
        let datas = ConstData.getPlayListTestDatas();
        onUpdateListData(datas);
    }

    //
    // onUpdateListData : 更新列表数据
    //
    function onUpdateListData(list) {
        let dts = [];
        let count = 0;
        for(let idx = list.length - 1; idx >= 0; idx--) {
            if (count >= 3) {
                break;
            }
            let itemObj = list[idx];
            dts.push(itemObj);

            count++;
        }
        listId.init(dts);
    }

    // 列表
    CardList {
        id: listId

        anchors {
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            topMargin: playHistoryViewId.padTop
        }

        showVerticalScrollBar: false
        width: listWidth
        height: parent.height - playHistoryViewId.padTop - playHistoryViewId.padBottom

    } // end CardList

}
