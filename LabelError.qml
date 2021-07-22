import QtQuick 2.12

Item {
    id: root

    property color backgroundColor: "#a5314c"
    property color borderColor: "red"

    property int borderWidth: 2

    property string textLabel: ""
    property color textColor: "white"

    Rectangle {
        id: frame
        height: root.height
        width: root.width
        color: backgroundColor
        border.width: borderWidth
        border.color: borderColor

        Text {
            id: content
            text: textLabel
            textFormat: Text.MarkdownText
            width: frame.width
            wrapMode: Text.WordWrap
            color: textColor
            padding: 5
            font.pointSize: 7
        }
    }

}
