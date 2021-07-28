import QtQuick 2.12

Item {
    id: root

    property color backgroundColor: "#a5314c"
    property color borderColor: "red"
    property int borderWidth: 2

    property string textLabel: "Text"
    property color textColor: "white"
    property alias textFormat: content.textFormat
    property alias wrapMode: content.wrapMode
    property int paddingLabel: 5
    property int fontPointSize: 7

    Rectangle {
        height: parent.height
        width: parent.width
        color: backgroundColor
        border.color: borderColor
        border.width: borderWidth

        Text {
            id: content
            width: parent.width
            text: textLabel
            color: textColor
            textFormat: Text.MarkdownText
            wrapMode: Text.WordWrap
            padding: paddingLabel
            font.pointSize: fontPointSize
        }
    }
}
