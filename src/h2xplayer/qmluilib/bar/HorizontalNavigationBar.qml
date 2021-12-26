import QtQuick 2.0
import QtQuick.Controls 2.12

import "../common/GlobalValue.js" as GlobalValue
import "../common/Tool.js" as Tool

/*
 * ClassName: HorizontalNavigationBar
 * Desc: 水平导航栏
 * Author: zfs
 * Date: 2021-12-26 10:01
 */

Item {
    id: ctrlRootId

    signal buttonClick(var id, int index)

    // 允许重复标志，如果为true则会重复觖发，如果为false则不会触发
    property bool repeatEnable: false

    // 导航栏按钮列表
    property ListModel datas: ListModel{}
    // 导航栏缓存数据
    property var cacheDatas: []
    // 当前选中项
    property int curIndex: -1

    // 导航栏背景色
    property var backColor: "#FFFFFF"
    // 导航背景窗口圆角值
    property int backRadius: 10

    // 导航栏按钮属性
    property int buttonWidth: 120
    property int buttonHeight: 50
    property int buttonRaidus: 10

    // 导航栏按钮间隔
    property int buttonSpaceWidth: 2

    // 导航栏按钮边线
    property bool buttonLineEnable: true
    property int buttonLineWidth: 1
    property var buttonLineColor: "#999999"

    // 导航栏按钮背景颜色
    property var buttonDefBackColor: "#6495ED"
    property var buttonSelBackColor: "#4169E1"

    // 导航栏按钮文本颜色
    property var buttonDefTextColor: "#000000"
    property var buttonSelTextColor: "#CCCCCC"

    // 字体
    property var fontFamily: GlobalValue.def_font_family_
    property var fontPixelSize: 18

    // 边界距离
    property int leftPadding: 10
    property int topPadding: 5
    property int rightPadding: 10
    property int bottomPadding: 5

    // 背景窗口
    Rectangle {
        id: bkWinId

        anchors.fill: parent
        color: backColor
        radius: backRadius

        // 导航栏列表
        Flickable {
            id: flickableId

            anchors {
                left: parent.left
                leftMargin: leftPadding
                top: parent.top
                topMargin: topPadding
            }

            width: Math.abs(parent.width) - leftPadding - rightPadding
            height: Math.abs(parent.height) - topPadding - bottomPadding
            contentWidth: width
            contentHeight: height

            // 导航列表
            Row {

                spacing: buttonSpaceWidth

                Repeater {
                    model: datas

                    // 导航按钮
                    Rectangle {
                        id: buttonId

                        width: buttonWidth
                        height: buttonHeight
                        color:  index != curIndex ? buttonDefBackColor : buttonSelBackColor
                        radius: buttonRaidus

                        // 按钮文本
                        Text {
                            anchors {
                                horizontalCenter: parent.horizontalCenter
                                verticalCenter: parent.verticalCenter
                            }
                            clip: true
                            font.family: fontFamily
                            font.pixelSize: fontPixelSize
                            color: index == curIndex ? buttonSelTextColor : buttonDefTextColor
                            text: name
                        }

                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                let isChanged = index == curIndex ? false : true;
                                if (isChanged) {
                                    curIndex = index

                                    buttonClick(getItemId(curIndex), curIndex);
                                }
                                else if (repeatEnable) {
                                    buttonClick(getItemId(curIndex), curIndex);
                                }
                            }
                        }

                    } // end buttonId Rectangle

                } // end Repeater

            } // end Row

        } // end flickableId Flickable

    } // end bkWinId Rectangle

    /*
     * Func: init
     * Desc: 初始化导航栏数据
     * Author: zfs
     * Date: 2021-12-26 10:25
     * @list: 导航栏数据列表
     * @curIdx: 当前选中的项
     */
    function init(list, curIdx = 0) {
        let paramObj = {
            list: list,
            curIdx: curIdx
        }
        Tool.printMsg("HorizontalNavigationBar.qml init params : " + JSON.stringify(paramObj));

        curIndex = -1;
        datas.clear();
        cacheDatas = [];

        // 更新数据
        if (list !== null && list.length > 0) {
            for(let i = 0; i < list.length; i++) {
                let itemObj = list[i];

                // 保存缓存
                cacheDatas.push(itemObj);
                // 保存到模型
                datas.append(itemObj)
            }

            if (curIdx >= 0 && curIdx < cacheDatas.length) {
                curIndex = curIdx
            }
            else {
                curIndex = 0;
            }
        }

        // 更新导航栏窗口大小
        resize();
    }

    /*
     * Func: resize
     * Desc: 调整导航栏窗口大小
     * Author: zfs
     * Date: 2021-12-26 10:46
     */
    function resize() {
        let winWidth = getMaxWidth();
        let winHeight = getMaxHeight();

        ctrlRootId.width = winWidth;
        ctrlRootId.height = winHeight;

        let msg = "HorizontalNavigationBar.qml resize new width: " + winWidth + " new height:" + winHeight;
        Tool.printMsg(msg);
    }

    function getMaxWidth() {
        let buttonCount = datas.count;
        let winWidth = leftPadding + rightPadding + (buttonSpaceWidth + buttonWidth) * buttonCount;
        return winWidth;
    }

    function getMaxHeight() {
        let winHeight = topPadding + bottomPadding + buttonHeight;
        return winHeight;
    }

    /*
     * Function: getItemId
     * Desc: 获取指定序号对应的ID
     * Author: zfs
     * Date: 2021-12-26 12:20
     */
    function getItemId(index) {
        if (index >= 0 && index < cacheDatas.length) {
            let itemObj = cacheDatas[index];
            return itemObj["id"];
        }
        return "";
    }

}
