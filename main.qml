import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.12

Window {
    id: root
    visible: true
    width: 640
    minimumWidth: 500
    height: 480
    minimumHeight: 300
    title: qsTr("ImageTagger")

    Loader {
        id: loader
        source: Qt.resolvedUrl("qrc:/LoginPage.qml")
        anchors.fill: parent
    }
}
