import QtQuick 2.0
import QtQuick.Controls 2.12

/*
 * ClassName: HorizontalImageCard
 * Desc: 水平图片卡片类(即图片在左边，图片信息在右边)
 * Author: zfs
 * Date: 2022-01-01 13:37
 */

Rectangle {
    id: cradId

    // 卡片数据
    property var idValue: ""
    property var nameValue: ""

    // 卡片属性
    property int cardWidth: 700
    property int cardHeight: 300
    property int cardRadius: 20

    // 卡片背景颜色
    property var cardBkColor: "#FFFFFF"

    property int itemSpaceWidth: 20

    // 卡外图标属性
    property int cardImgWidth: 260
    property int cardImgHeight: 260

    property int cardBorderWidth: 1
    property var cardBorderColor: Qt.rgba(0/255, 120/255, 116/255, 0.1)

    width: cardWidth
    height: cardHeight
    radius: cardRadius
    color: cardBkColor

    // 边框
    border.width: cardBorderWidth
    border.color: cardBorderColor

    // 标题栏
    Rectangle {
        anchors {
            top: parent.top
            topMargin: itemSpaceWidth
            right: parent.right
            rightMargin: itemSpaceWidth
        }
        width: parent.width - cardImgWidth - itemSpaceWidth * 3
        height: 40
        color: "transparent"

        Text {
            anchors {
                verticalCenter: parent.verticalCenter
                horizontalCenter: parent.horizontalCenter
            }
            color: "#000000"
            text: nameValue
        }

    }

}
