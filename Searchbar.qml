import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: root

    property string defaultText: "Text"
    property color defaultTextColor: "grey"
    property int defaultMaximumLength: 50

    property color backgroundColor: "white"
    property color borderColor: "black"
    property int borderWidth: 2
    property int defaultRadius: 20

    TextField {
        width: parent.width
        maximumLength: defaultMaximumLength
        color: defaultTextColor
        selectByMouse: true
        selectedTextColor: "white"
        placeholderText: defaultText
        enabled: true

        background: Rectangle {
            color: backgroundColor
            border.color: borderColor
            border.width: borderWidth
            radius: defaultRadius
        }

        onFocusChanged: {
            color = "black"
        }
    }
}
