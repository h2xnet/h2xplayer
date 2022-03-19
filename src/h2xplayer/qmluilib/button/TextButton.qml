import QtQuick 2.0
import QtQuick.Controls 2.12

import "../common/GlobalValue.js" as GlobalValue

/*
 * ClassName: TextButton
 * Desc: 文本按钮
 * Author: zfs
 * Date: 2022-01-03 09:47
 */

Rectangle {
    id: textButtonId

    signal textButtonClick();

    // 字体属性
    property var fontFamily: GlobalValue.def_font_family_
    property int fontPixelSize: GlobalValue.def_font_pixel_size_
    property var fontColor: GlobalValue.def_font_color_

    // 按钮背景颜色
    property var bkColor: "transparent"

    // 按钮圆角值
    property int buttonRadius: 5

    // 按钮文本内容
    property var buttonText: ""

    // 水平文本对齐方式
    property var horizontalAlign: 'center' // left / center / right
    property int horizontalOffset: 10

    // 边框
    property int borderWidth: 1
    property var borderColor: GlobalValue.def_border_color_

    // 设置按钮属性
    color: bkColor
    radius: buttonRadius
    border.width: borderWidth
    border.color: borderColor

    Text {
        id: buttonTextId

        // 水平对齐
        horizontalAlignment: {
            if (horizontalAlign === 'left') {
                return Text.AlignLeft
            }
            else if (horizontalAlign === 'right') {
                return Text.AlignRight
            }
            else {
                return Text.AlignHCenter
            }
        }

        // 垂直对齐
        anchors {
            left: parent.left
            leftMargin: horizontalOffset
            verticalCenter: parent.verticalCenter
        }

        font.family: fontFamily
        font.pixelSize: fontPixelSize
        color: fontColor

        width: parent.width - 2 * horizontalOffset
        wrapMode: Text.NoWrap   // 不换行
        elide: Text.ElideRight  // 右边显示省略号

        text: buttonText
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: Qt.PointingHandCursor
        onClicked: {
            textButtonClick();
        }
    }

} // end textButtonId Rectangle
