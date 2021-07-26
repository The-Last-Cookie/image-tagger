import QtQuick 2.12

Item {
    id: root

    property color backgroundColor: "#a5314c"

    property color borderColor: "red"
    property int borderWidth: 2

    property string textLabel: ""
    property color textColor: "white"

    Rectangle {
        height: parent.height
        width: parent.width
        color: backgroundColor
        border.width: borderWidth
        border.color: borderColor

        Text {
            text: textLabel
            textFormat: Text.MarkdownText
            wrapMode: Text.WordWrap
            width: parent.width
            color: textColor
            padding: 5
            font.pointSize: 7
        }
    }
}
