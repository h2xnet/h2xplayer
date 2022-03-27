import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.2

import "../common/GlobalValue.js" as GlobalValue
import "../common/Tool.js" as Tool
import "../card"

/*
 * ClassName: CardList
 * Desc: 卡片列表类
 * Author: zfs
 * Date: 2022-01-01 13:36
 */

Item {
    id: cardListId

    signal cardItemOpenMedia(int index);

    // 显示滚动条
    property bool showVerticalScrollBar: true

    // 数据映射模型
    property var roleIdKey: "id"
    property var roleTitleKey: "title"
    property var roleDescKey: "desc"
    property var roleCoverImgKey: "coverUrl"
    property var roleTotalTimesKey: "totalTimes"
    property var roleStarKey: "star"
    property var roleSourceNameKey: "sourceName"

    property var rolePlayNumsKey: "playNums"
    property var roleLikeNumsKey: "likeNums"
    property var roleCollectNumsKey: "collectNums"
    property var roleForwardNumsKey: "forwardNums"

    // 数据模型
    property ListModel dataModel: ListModel{}
    // 数据缓存
    property var cacheDatas: []

    // 背景颜色
    property var bkColor: "transparent"

    property var fontFamily: GlobalValue.def_font_family_

    // 滚动条
    property int scrollBarWidth: GlobalValue.def_scroll_bar_width_
    property int scrollBarRadius: GlobalValue.def_scroll_bar_radius_
    property var scrollBarColor: GlobalValue.def_scroll_bar_color_

    // 页边间距
    property var padLeft: 0
    property var padTop: 0
    property var padRight: 0
    property var padBottom: 0

    property int itemSpaceWidth: GlobalValue.def_item_space_width_

    // 背景窗口
    Rectangle {
        id: bkWinId

        anchors.fill: parent
        color: bkColor

        Flickable {
            id: flickableId

            anchors {
                left: parent.left
                leftMargin: padLeft
                top: parent.top
                topMargin: padTop
            }

            width: Math.abs(parent.width - padLeft - padRight)
            height: Math.abs(parent.height - padTop - padBottom)
            contentWidth: width
            contentHeight: contentId.implicitHeight
            clip: true

            // 垂直滚动条
            ScrollBar.vertical: ScrollBar {
                anchors {
                    top: parent.top
                    topMargin: 0
                    right: parent.right
                }

                visible: (showVerticalScrollBar && (parent.height < parent.contentHeight))

                width: scrollBarWidth
                height:parent.height

                contentItem: Rectangle {
                    width: parent.width
                    height: parent.height
                    radius: scrollBarRadius
                    color: scrollBarColor
                }

            } // end ScrollBar.vertical: ScrollBar

            ColumnLayout {
                id: contentId

                spacing: itemSpaceWidth

                width: flickableId.width

                Repeater {
                    model: dataModel

                    // 加载列表项
                    Loader {
                        sourceComponent: HorizontalImageCard {
                            //cardWidth: 960

                            roleIdValue: dataModel.get(index)[roleIdKey]
                            roleTitleValue: dataModel.get(index)[roleTitleKey]
                            roleDescValue: dataModel.get(index)[roleDescKey]
                            roleStarValue: dataModel.get(index)[roleStarKey]
                            roleCoverImgIsUrl: true
                            roleCoverImgValue: dataModel.get(index)[roleCoverImgKey]
                            roleTotalTimesValue: Tool.getTimeStr(dataModel.get(index)[roleTotalTimesKey])
                            roleSourceNameValue: dataModel.get(index)[roleSourceNameKey]
                            rolePlayNumsValue: Tool.getNumberStr(dataModel.get(index)[rolePlayNumsKey])
                            roleLikeNumsValue: Tool.getNumberStr(dataModel.get(index)[roleLikeNumsKey])
                            roleCollectNumsValue: Tool.getNumberStr(dataModel.get(index)[roleCollectNumsKey])
                            roleForwardNumsValue: Tool.getNumberStr(dataModel.get(index)[roleForwardNumsKey])


                            onOpenMediaClick: {
                                console.log("CardList.qml onOpenMediaClick.");
                                cardItemOpenMedia(index);
                            }
                        }

                        onLoaded: {
                            console.log("CardList.qml onLoaded index : " + index)

                        }
                    } // end Loader

                } // end Repeater

            } // end ColumnLayout

        } // end flickableId Flickable

    } // end bkWinId Rectangle

    /*
     * ClassName: init
     * Desc: 初始化
     * Author: zhaofushou
     * Date: 2022-02-01 14:37
     */
    function init(list) {
        console.log("CardList.qml init.");
        cacheDatas = [];
        dataModel.clear();

        // 更新数据
        if (list !== null && list.length > 0) {
            for(let i = 0; i < list.length; i++) {
                let itemData = list[i];

                cacheDatas.push(itemData);
                dataModel.append(itemData);
            }
        }


    }

}
