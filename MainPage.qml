import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Item {
    id: root

    function switchVisibilityOfExtendableSidebar() {
        if (extendableSidebar.visible) {
            extendableSidebar.visible = false
        } else {
            extendableSidebar.visible = true
        }
    }

    Rectangle {
        id: sidebar
        width: 100
        height: parent.height
        anchors.left: parent.left
        color: "blue"

        MouseArea {
            id: sideBarMouseArea
            anchors.fill: parent
            hoverEnabled: true

            onHoveredChanged: {
                if (sideBarMouseArea.containsMouse) {
                    extendableSidebar.visible = true
                }

                if (!sideBarMouseArea.containsMouse && !extendableSidebar.visible) {
                    extendableSidebar.visible = false
                }
            }

            onClicked: {
                switchVisibilityOfExtendableSidebar()
            }
        }

        ColumnLayout {
            spacing: 5

            Button {
                Layout.fillWidth: true
                Layout.preferredHeight: 30
                hoverEnabled: true
                text: qsTr("Home")

                onClicked: {
                    switchVisibilityOfExtendableSidebar()
                    content.replace("qrc:/HomePage.qml", StackView.Immediate)
                }

                onHoveredChanged: {
                    if (this.hovered) {
                        extendableSidebar.visible = true
                    }

                    if (!this.hovered && !extendableSidebar.visible) {
                        extendableSidebar.visible = false
                    }
                }
            }

            Button {
                Layout.fillWidth: true
                Layout.preferredHeight: 30
                hoverEnabled: true
                text: qsTr("Tags")

                onClicked: {
                    switchVisibilityOfExtendableSidebar()
                    content.replace("qrc:/TagPage.qml", StackView.Immediate)
                }

                onHoveredChanged: {
                    if (this.hovered) {
                        extendableSidebar.visible = true
                    }

                    if (!this.hovered && !extendableSidebar.visible) {
                        extendableSidebar.visible = false
                    }
                }
            }

            Button {
                Layout.fillWidth: true
                Layout.preferredHeight: 30
                hoverEnabled: true
                text: qsTr("Groups")

                onClicked: {
                    switchVisibilityOfExtendableSidebar()
                    content.replace("qrc:/GroupPage.qml", StackView.Immediate)
                }

                onHoveredChanged: {
                    if (this.hovered) {
                        extendableSidebar.visible = true
                    }

                    if (!this.hovered && !extendableSidebar.visible) {
                        extendableSidebar.visible = false
                    }
                }
            }

            Button {
                Layout.fillWidth: true
                Layout.preferredHeight: 30
                hoverEnabled: true
                text: qsTr("Auhors")

                onClicked: {
                    switchVisibilityOfExtendableSidebar()
                    content.replace("qrc:/AuthorPage.qml", StackView.Immediate)
                }

                onHoveredChanged: {
                    if (this.hovered) {
                        extendableSidebar.visible = true
                    }

                    if (!this.hovered && !extendableSidebar.visible) {
                        extendableSidebar.visible = false
                    }
                }
            }
        }

        ColumnLayout {
            anchors.bottom: parent.bottom
            spacing: 5

            Button {
                Layout.fillWidth: true
                Layout.preferredHeight: 30
                hoverEnabled: true
                text: qsTr("Account")

                onClicked: {
                    switchVisibilityOfExtendableSidebar()
                    content.replace("qrc:/AccountPage.qml", StackView.Immediate)
                }

                onHoveredChanged: {
                    if (this.hovered) {
                        extendableSidebar.visible = true
                    }

                    if (!this.hovered && !extendableSidebar.visible) {
                        extendableSidebar.visible = false
                    }
                }
            }

            Button {
                Layout.fillWidth: true
                Layout.preferredHeight: 30
                hoverEnabled: true
                text: qsTr("Settings")

                onClicked: {
                    switchVisibilityOfExtendableSidebar()
                    content.replace("qrc:/SettingsPage.qml", StackView.Immediate)
                }

                onHoveredChanged: {
                    if (this.hovered) {
                        extendableSidebar.visible = true
                    }

                    if (!this.hovered && !extendableSidebar.visible) {
                        extendableSidebar.visible = false
                    }
                }
            }
        }
    }

    StackView {
        id: content
        initialItem: "qrc:/HomePage.qml"
        anchors.left: sidebar.right
        anchors.right: parent.right
        height: parent.height
    }

    Rectangle {
        id: extendableSidebar
        anchors.left: sidebar.right
        height: parent.height
        width: parent.width
        visible: false

        MouseArea {
            id: extendableSidebarMouseArea
            anchors.fill: parent
            hoverEnabled: true

            onClicked: {
                extendableSidebar.visible = false
            }

            ColumnLayout {
                Layout.fillWidth: true
                Layout.preferredHeight: 30
                spacing: 5
                z: 1

                Button {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 30
                    text: qsTr("Home")

                    onClicked: {
                        extendableSidebar.visible = false
                        content.replace("qrc:/HomePage.qml", StackView.Immediate)
                    }
                }

                Button {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 30
                    text: qsTr("Tags")

                    onClicked: {
                        extendableSidebar.visible = false
                        content.replace("qrc:/TagPage.qml", StackView.Immediate)
                    }
                }

                Button {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 30
                    text: qsTr("Groups")

                    onClicked: {
                        extendableSidebar.visible = false
                        content.replace("qrc:/GroupPage.qml", StackView.Immediate)
                    }
                }

                Button {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 30
                    text: qsTr("Auhors")

                    onClicked: {
                        extendableSidebar.visible = false
                        content.replace("qrc:/AuthorPage.qml", StackView.Immediate)
                    }
                }
            }

            ColumnLayout {
                Layout.fillWidth: true
                Layout.preferredHeight: 30
                anchors.bottom: parent.bottom
                spacing: 5
                z: 1

                Button {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 30
                    text: qsTr("Account")

                    onClicked: {
                        extendableSidebar.visible = false
                        content.replace("qrc:/AccountPage.qml", StackView.Immediate)
                    }
                }

                Button {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 30
                    text: qsTr("Settings")

                    onClicked: {
                        extendableSidebar.visible = false
                        content.replace("qrc:/SettingsPage.qml", StackView.Immediate)
                    }
                }
            }

            Rectangle {
                z: 0
                anchors.fill: parent
                color: Qt.rgba(0, 0, 0, 0.5)
            }
        }
    }
}
