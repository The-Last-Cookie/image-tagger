import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import "qrc:/uicomponents" as UIComponents
import AccessControlSystem 1.0

Item {
    id: root

    ColumnLayout {
        spacing: 0
        anchors.fill: parent
        anchors.leftMargin: 10

        Text {
            text: qsTr("Account")
            color: "black"
            font.pointSize: 24
            font.bold: true
        }

        ColumnLayout {
            Layout.alignment: Qt.AlignTop

            Text {
                text: qsTr("Change password")
                color: "black"
                font.pointSize: 12
            }

            RowLayout {
                spacing: 5
                height: 30

                Text {
                    text: qsTr("Old password:")
                    Layout.alignment: Qt.AlignLeft
                }

                TextField {
                    id: txtOldPassword
                    Layout.preferredHeight: 30
                    echoMode: TextInput.Password
                }
            }

            RowLayout {
                spacing: 5
                height: 30

                Text {
                    text: qsTr("New password:")
                }

                TextField {
                    id: txtNewPassword
                    Layout.preferredHeight: 30
                    echoMode: TextInput.Password
                }
            }

            RowLayout {
                spacing: 5
                height: 30

                Text {
                    text: qsTr("New password (confirm):")
                }

                TextField {
                    id: txtNewPasswordConfirm
                    Layout.preferredHeight: 30
                    echoMode: TextInput.Password
                }
            }

            Button {
                Layout.preferredHeight: 30
                Layout.preferredWidth: 90

                Text {
                    text: qsTr("Change password")
                    anchors.centerIn: parent
                    color: "white"
                }

                background: Rectangle {
                    color: "green"
                }

                onClicked: {
                    if (!AccessControlSystem.changePassword(txtOldPassword.text, txtNewPassword.text, txtNewPasswordConfirm.text)) {
                        infoPasswordNotChanged.visible = true
                    } else {
                        txtOldPassword.text = ""
                        txtNewPassword.text = ""
                        txtNewPasswordConfirm.text = ""
                        infoPasswordNotChanged.visible = false
                    }
                }
            }

            UIComponents.InfoLabel {
                id: infoPasswordNotChanged
                Layout.preferredHeight: 30
                Layout.preferredWidth: 250
                textLabel: qsTr("There seems to be a problem. Either your current password is not correct, the new password is not safe enough or the two new passwords aren't the same.")
                visible: false
            }
        }

        Button {
            Layout.preferredHeight: 30
            Layout.preferredWidth: 50

            Text {
                text: qsTr("Logout")
                anchors.centerIn: parent
            }

            onClicked: {
                AccessControlSystem.logout()
                loader.source = Qt.resolvedUrl("qrc:/LoginPage.qml")
            }
        }

        Button {
            Layout.preferredHeight: 30
            Layout.preferredWidth: 80

            Text {
                text: qsTr("Delete account")
                anchors.centerIn: parent
                color: "white"
            }

            background: Rectangle {
                color: "red"
            }

            onClicked: {
                AccessControlSystem.deleteUser()
                loader.source = Qt.resolvedUrl("qrc:/LoginPage.qml")
            }
        }
    }
}
