import QtQuick 2.0
import QtQuick.Controls 2.12

Item {
    id: root

    Rectangle {
        width: parent.width / 2
        height: parent.height / 2
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        color: "#1f79d3"

        Button {
            id: loginGuest
            text: "Login as guest"
            width: parent.width / 2
            height: parent.height / 4
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            onClicked: frame.replace(Qt.resolvedUrl("qrc:/MainPage.qml"))
        }
    }
}
