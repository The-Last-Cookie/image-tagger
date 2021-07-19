import QtQuick 2.0
import QtQuick.Controls 2.12

Item {
    id: root

    Rectangle {
        width: parent.width
        height: parent.height
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        color: "red"

        Text {
            text: "hello"
            font.pointSize: 24
        }
    }

    Drawer {
        id: sidebar

        Label {
            id: content

            text: "Aa"
            font.pixelSize: 96
            anchors.fill: parent
            verticalAlignment: Label.AlignVCenter
            horizontalAlignment: Label.AlignHCenter
        }
    }
}
