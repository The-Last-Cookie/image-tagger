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

    StackView {
        id: frame
        initialItem: loginPage
        anchors.fill: parent

        property alias frame: frame

        LoginPage {
            id: loginPage
        }

        MainPage {
            id: mainPage
        }
    }
}
