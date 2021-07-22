import QtQuick 2.12
import QtQuick.Controls 2.12

import "uicomponents" as UIComponents

Item {
    id: root

    Rectangle {
        id: sidebar
        width: 100
        height: parent.height
        anchors.left: parent.left
        color: "blue"

        StackView {
            id: content
            initialItem: "qrc:/HomePage.qml"
            anchors.left: sidebar.right
        }

        Column {
            anchors.fill: parent
            spacing: 5

            Button {
                text: qsTr("Home")
                onClicked: {
                    content.replace("qrc:/HomePage.qml", StackView.Immediate)
                }
            }

            Button {
                text: qsTr("Tags")
                onClicked: {
                    content.replace("qrc:/TagPage.qml", StackView.Immediate)
                }
            }

            Button {
                text: qsTr("Groups")
                onClicked: {
                    content.replace("qrc:/GroupPage.qml", StackView.Immediate)
                }
            }

            Button {
                text: qsTr("Auhors")
                onClicked: {
                    content.replace("qrc:/AuthorPage.qml", StackView.Immediate)
                }
            }

            Button {
                text: qsTr("Account")
                onClicked: {
                    content.replace("qrc:/AccountPage.qml", StackView.Immediate)
                }
            }

            Button {
                text: qsTr("Settings")
                onClicked: {
                    content.replace("qrc:/SettingsPage.qml", StackView.Immediate)
                }
            }
        }
    }
}
