import QtQuick 2.0
import QtQuick.Controls 2.12

import "../common/GlobalValue.js" as GlobalValue

/*
 * ClassName: HorizontalImageButton
 * Desc: 水平图标按钮（即图标在左边，按钮文本在右边）
 * Author: zfs
 * Date: 2022-01-03 11:00
 */

Rectangle {
    id: hImageButtonId

    signal horizontalImageButtonClick();

    // 字体属性
    property var fontFamily: GlobalValue.def_font_family_
    property int fontPixelSize: GlobalValue.def_font_pixel_size_
    property var fontColor: GlobalValue.def_font_color_

    // 按钮背景颜色
    property var bkColor: "transparent"

    // 按钮圆角值
    property int buttonRadius: 5

    property int itemSpaceWidth: 10

    // 按钮图标
    property bool imgIsUrl: true
    property var imgPath: ""
    property int imgWidth: 80
    property int imgHeight: 80

    // 按钮文本内容
    property var buttonText: ""

    // 边框
    property int borderWidth: 1
    property var borderColor: GlobalValue.def_border_color_

    // 设置按钮属性
    color: bkColor
    radius: buttonRadius
    border.width: borderWidth
    border.color: borderColor

    // 按钮图标
    Image {
        anchors {
            verticalCenter: parent.verticalCenter
            left: parent.left
            leftMargin: hImageButtonId.itemSpaceWidth
        }

        sourceSize.width: imgWidth
        sourceSize.height: imgHeight
        source: imgIsUrl ? imgPath : "file:///" + imgPath
    }

    // 按钮文本
    Text {
        id: buttonTextId

        anchors {
            left: parent.left
            leftMargin: imgWidth + 2 * hImageButtonId.itemSpaceWidth
            verticalCenter: parent.verticalCenter
        }

        font.family: fontFamily
        font.pixelSize: fontPixelSize
        color: fontColor
        width: parent.width - imgWidth - 3 * hImageButtonId.itemSpaceWidth

        // 省略号
        wrapMode: Text.NoWrap
        elide: Text.ElideRight

        text: buttonText
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: Qt.PointingHandCursor
        onClicked: {
            horizontalImageButtonClick();
        }
    }

} // end hImageButtonId Rectangle
