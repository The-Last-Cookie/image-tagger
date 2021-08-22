import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import "qrc:/uicomponents" as UIComponents

Item {
    id: root
    anchors.fill: parent

    Rectangle {
        width: parent.width / 2
        height: parent.height / 1.5
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        color: "#1f79d3"

        StackView {
            id: frame
            anchors.fill: parent
            initialItem: Qt.resolvedUrl("qrc:/LoginForm.qml")
        }
    }
}
