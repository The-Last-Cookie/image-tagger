import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import "uicomponents" as UIComponents

Item {
    id: root

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        Text {
            Layout.alignment: Qt.AlignCenter
            text: qsTr("Login")
            font.pointSize: 24
        }

        TextField {
            id: inputLoginName
            Layout.alignment: Qt.AlignCenter
            Layout.preferredHeight: 30
            Layout.preferredWidth: parent.width / 2
            maximumLength: 50
            color: "grey"
            selectByMouse: true
            selectedTextColor: "white"
            placeholderText: qsTr("Name")

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

        TextField {
            id: inputLoginPassword
            Layout.alignment: Qt.AlignCenter
            Layout.preferredHeight: 30
            Layout.preferredWidth: parent.width / 2
            maximumLength: 50
            color: "grey"
            selectByMouse: true
            selectedTextColor: "white"
            placeholderText: qsTr("Password")

            background: Rectangle {
                color: "white"
                border.color: "black"
                border.width: 2
                radius: 20
            }

            onFocusChanged: {
                color = "black"
                echoMode = TextInput.Password
            }
        }

        Text {
            Layout.preferredHeight: 10
            Layout.topMargin: 10
            Layout.leftMargin: 10
            text: qsTr("New here? Create new account")
            color: "blue"

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    inputLoginName.placeholderText = qsTr("Name")
                    inputLoginPassword.placeholderText = qsTr("Password")
                    frame.push(Qt.resolvedUrl("qrc:/CreateAccountForm.qml"), StackView.Immediate)
                }
            }
        }

        Button {
            Layout.preferredWidth: parent.width / 4
            Layout.preferredHeight: parent.height / 6
            Layout.alignment: Qt.AlignRight
            text: qsTr("Login")

            onClicked: {
                if (!acs.login(inputLoginName.text, inputLoginPassword.text, 0)) {
                    infoUserLoginNotSuccesful.visible = true
                    return
                }

                loader.source = Qt.resolvedUrl("qrc:/MainPage.qml")
            }
        }

        UIComponents.LabelError {
            id: infoUserLoginNotSuccesful
            Layout.preferredHeight: 20
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignCenter
            Layout.leftMargin: 30
            Layout.rightMargin: 30
            visible: false

            textLabel: qsTr("Username or password not correct.")
        }

        Button {
            text: qsTr("Login as guest")
            Layout.preferredWidth: parent.width / 3
            Layout.preferredHeight: parent.height / 6
            Layout.alignment: Qt.AlignCenter

            onClicked: {
                //if (acs.login("", "", 1)) {
                loader.source = Qt.resolvedUrl("qrc:/MainPage.qml")
                //}
            }

            onHoveredChanged: {
                if (infoLoginAsGuest.visible) {
                    infoLoginAsGuest.visible = false
                } else {
                    infoLoginAsGuest.visible = true
                }
            }
        }

        UIComponents.LabelError {
            id: infoLoginAsGuest
            Layout.preferredHeight: 20
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignCenter
            Layout.leftMargin: 30
            Layout.rightMargin: 30
            visible: false

            textLabel: qsTr("Please be aware that your files will only be available as long as the application is running.")
        }
    }

}
