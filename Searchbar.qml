import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: root

    TextField {
        height: 30
        width: parent.width
        anchors.horizontalCenter: parent.horizontalCenter
        maximumLength: 50
        color: "grey"
        selectByMouse: true
        selectedTextColor: "white"
        placeholderText: qsTr("Name")
        enabled: true

        background: Rectangle {
            color: "white"
            border.color: "black"
            border.width: 2
            radius: 20
        }

        onFocusChanged: {
            color = "black"
        }
    }
}
