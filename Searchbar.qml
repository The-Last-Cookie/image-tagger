import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: root

    property string defaultText: "Text"
    property color defaultTextColor: "grey"
    property int defaultMaximumLength: 200

    property color backgroundColor: "white"
    property color borderColor: "black"
    property int borderWidth: 2
    property int defaultRadius: 20

    property alias textField: textField

    TextField {
        id: textField
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
