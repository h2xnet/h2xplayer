import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.0

import "../button"

import "../common/GlobalValue.js" as GlobalValue;

/*
 * ClassName: HorizontalImageCard
 * Desc: 水平图片卡片类(即图片在左边，图片信息在右边)
 * Author: zfs
 * Date: 2022-01-01 13:37
 */

Rectangle {
    id: cradId

    // 卡片角色数据
    property var roleIdValue: ""    // ID
    property var roleTitleValue: "" // 标题
    property var roleDescValue: ""  // 描述
    property var roleStarValue: -1  // 星级

    property bool roleCoverImgIsUrl: true   // 封面图片是否为网络图片，true则是网络图片，false则是本地图片
    property var roleCoverImgValue: ""  // 封面图片

    property var roleTotalTimesValue: ''    // 总时间长度字符串
    property var roleSourceNameValue: ''    // 来源名称

    // 卡片属性
    property int cardWidth: 850
    property int cardHeight: 300
    property int cardRadius: 20

    // 卡片背景颜色
    property var cardBkColor: "#FFFFFF"

    // 卡片元素间隔大小
    property int itemSpaceWidth: 20

    // 卡片边框属性
    property int cardBorderWidth: GlobalValue.def_border_width_
    property var cardBorderColor: GlobalValue.def_border_color_

    // 卡外封面图片
    property int coverImgWidth: 300
    property int coverImgHeight: 260

    // 标题栏
    property int cardTitleLineHeight: GlobalValue.def_title_line_height_
    property int cardTitleMaxLineCount: 2
    property int cardTitleHeight: cardTitleMaxLineCount * GlobalValue.def_title_line_height_
    property var cardTitleTextColor: GlobalValue.def_title_text_color_
    property var cardTitlePixelSize: GlobalValue.def_title_pixel_size_

    // 星级
    property int cardStarHeight: 20

    // 描述
    property var cardDescTextColor: GlobalValue.def_desc_text_color_
    property var cardDescPixelSize: GlobalValue.def_desc_pixel_size_

    // 底部选项卡
    property int cardOptionHeight: 40
    property int cardOptionSpaceWidth: 5
    property int cardOptionItemWidth: 80

    // 设置卡片属性
    width: cardWidth
    height: cardHeight
    radius: cardRadius
    color: cardBkColor
    border.width: cardBorderWidth
    border.color: cardBorderColor

    // 封面图标
    Image {
        id: coverImgId

        anchors {
            left: parent.left
            leftMargin: itemSpaceWidth
            verticalCenter: parent.verticalCenter
        }

        sourceSize.width: coverImgWidth
        sourceSize.height: coverImgHeight

        source: roleCoverImgIsUrl ? roleCoverImgValue : "file:///" + roleCoverImgValue

        // 时间字符串
        Rectangle {
            anchors {
                right: parent.right
                rightMargin: 10
                bottom: parent.bottom
                bottomMargin: 10
            }

            width: 110
            height: 32
            color: Qt.rgba(255, 255, 255, 0.8)
            radius: 5

            Text {
                anchors.centerIn: parent

                color: cardDescTextColor
                font.pixelSize: cardDescPixelSize

                text: roleTotalTimesValue
            }
        }

    } // end coverImgId Image

    // 右边介绍信息
    Rectangle {
        id: itemContentId

        anchors {
            top: parent.top
            topMargin: itemSpaceWidth
            left: parent.left
            leftMargin: coverImgWidth + itemSpaceWidth * 2
        }
        width: parent.width - coverImgWidth - itemSpaceWidth * 3
        height: parent.height - itemSpaceWidth * 2
        //color: "#FF2233"

        color: "transparent"

        // 标题栏
        Rectangle {
            id: titleWinId

            anchors {
                top: parent.top
                topMargin: 0
                right: parent.right
                rightMargin: 0
            }

            width: parent.width
            height: cardTitleHeight
            color: "transparent"

            Text {
                width: parent.width
                color: cardTitleTextColor
                font.pixelSize: cardTitlePixelSize
                //font.wordSpacing: 10

                lineHeight: cardTitleLineHeight // 行高
                maximumLineCount: cardTitleMaxLineCount // 最大行
                lineHeightMode: Text.FixedHeight // 行距
                wrapMode: Text.WrapAnywhere // 多行换行
                elide: Text.ElideRight // 超出部分右侧显示省略号

                text: roleTitleValue
            }
        } // end titleWinId Rectangle

        // 星级
        Rectangle {
            id: starWinId

            anchors {
                top: parent.top
                topMargin: cardTitleHeight
            }

            width: parent.width
            height: cardStarHeight

        } // end starWinId Rectangle

        // 描述信息
        Rectangle {
            id: descWinId

            width: parent.width
            color: "#888888"
        }

        // 选项
        RowLayout {
            id: optionRowId

            anchors {
                bottom: parent.bottom
                bottomMargin: 0
            }

            spacing: cardOptionSpaceWidth
            width: parent.width
            height: cardOptionHeight

            // 来源名称
            TextButton {
                id: sourceNameId

                height: parent.height
                width: 140
                horizontalAlign: 'left'
                horizontalOffset: 10
                fontPixelSize: GlobalValue.getFontPixelSize16()
                fontColor: GlobalValue.getFontColorBlue()
                borderWidth: 0
                buttonText: "来源：" + roleSourceNameValue

            } // end sourceNameId Rectangle

            // 播放数
            HorizontalImageButton {
                id: playNumsId

                imgWidth: 24
                imgHeight: 24
                imgIsUrl: true
                imgPath: "qrc:/qmluilib/imgs/toolicon/like.png"
                buttonText: "184933"
                itemSpaceWidth: 5
                fontPixelSize: GlobalValue.getFontPixelSize14()

                height: parent.height
                width: cardOptionItemWidth
            }

            // 点赞数
            HorizontalImageButton {
                id: likeNumsId

                imgWidth: 24
                imgHeight: 24
                imgIsUrl: true
                imgPath: "qrc:/qmluilib/imgs/toolicon/like.png"
                buttonText: "10384933"
                itemSpaceWidth: 5
                fontPixelSize: GlobalValue.getFontPixelSize14()

                height: parent.height
                width: cardOptionItemWidth
            }

            // 收藏数
            HorizontalImageButton {
                id: collectNumsId

                imgWidth: 24
                imgHeight: 24
                imgIsUrl: true
                imgPath: "qrc:/qmluilib/imgs/toolicon/like.png"
                buttonText: "4933"
                itemSpaceWidth: 5
                fontPixelSize: GlobalValue.getFontPixelSize14()

                height: parent.height
                width: cardOptionItemWidth
            }

            // 转发送
            HorizontalImageButton {
                id: forwardNumsId

                imgWidth: 24
                imgHeight: 24
                imgIsUrl: true
                imgPath: "qrc:/qmluilib/imgs/toolicon/like.png"
                buttonText: "33"
                itemSpaceWidth: 5
                fontPixelSize: GlobalValue.getFontPixelSize14()

                height: parent.height
                width: cardOptionItemWidth
            }

        } // end optionRowId RowLayout

    } // itemContentId

}
