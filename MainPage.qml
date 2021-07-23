import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: root

    function switchVisibilityOfExtendableSidebar() {
        if (extendableSidebar.visible) {
            extendableSidebar.visible = false
        } else {
            extendableSidebar.visible = true
        }
    }

    MouseArea {
        height: parent.height
        width: 100

        onClicked: {
            switchVisibilityOfExtendableSidebar()
        }

        Rectangle {
            id: sidebar
            width: parent.width
            height: parent.height
            anchors.left: parent.left
            color: "blue"

            Text {
                text: "hello"
            }

            StackView {
                id: content
                initialItem: "qrc:/HomePage.qml"
                anchors.left: sidebar.right
            }
        }

        Rectangle {
            id: extendableSidebar
            anchors.left: sidebar.right
            height: parent.height
            width: frame.width
            visible: false

            Column {
                anchors.fill: parent
                spacing: 2
                z: 1

                Button {
                    text: qsTr("Home")
                    onClicked: {
                        switchVisibilityOfExtendableSidebar()
                        content.replace("qrc:/HomePage.qml", StackView.Immediate)
                    }
                }

                Button {
                    text: qsTr("Tags")
                    onClicked: {
                        switchVisibilityOfExtendableSidebar()
                        content.replace("qrc:/TagPage.qml", StackView.Immediate)
                    }
                }

                Button {
                    text: qsTr("Groups")
                    onClicked: {
                        switchVisibilityOfExtendableSidebar()
                        content.replace("qrc:/GroupPage.qml", StackView.Immediate)
                    }
                }

                Button {
                    text: qsTr("Auhors")
                    onClicked: {
                        switchVisibilityOfExtendableSidebar()
                        content.replace("qrc:/AuthorPage.qml", StackView.Immediate)
                    }
                }

                Button {
                    text: qsTr("Account")
                    onClicked: {
                        switchVisibilityOfExtendableSidebar()
                        content.replace("qrc:/AccountPage.qml", StackView.Immediate)
                    }
                }

                Button {
                    text: qsTr("Settings")
                    onClicked: {
                        switchVisibilityOfExtendableSidebar()
                        content.replace("qrc:/SettingsPage.qml", StackView.Immediate)
                    }
                }
            }

            Rectangle {
                z: 0
                anchors.fill: parent
                opacity: 0.5
                color: "black"
            }
        }
    }
}
