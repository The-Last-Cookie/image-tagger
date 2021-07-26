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
            text: qsTr("Create new account")
            font.pointSize: 24
        }

        TextField {
            id: inputCreateName
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
            id: inputCreatePassword
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
            Layout.leftMargin: 10
            text: qsTr("Take me back")
            color: "blue"

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    inputCreateName.placeholderText = qsTr("Name")
                    inputCreatePassword.placeholderText = qsTr("Password")
                    frame.pop(StackView.Immediate)
                }
            }
        }

        Button {
            Layout.preferredWidth: parent.width / 3
            Layout.preferredHeight: parent.height / 6
            Layout.alignment: Qt.AlignRight
            text: qsTr("Create new account")

            onClicked: {
                if (!acs.createUser(inputCreateName.text, inputCreatePassword.text)) {
                    infoUserCreationNotSuccesful.visible = true
                    return
                }

                acs.login(inputCreateName.text, inputCreatePassword.text, 0)
                loader.source = Qt.resolvedUrl("qrc:/MainPage.qml")
            }
        }

        UIComponents.LabelError {
            id: infoUserCreationNotSuccesful
            Layout.preferredHeight: 60
            Layout.alignment: Qt.AlignCenter
            Layout.fillWidth: true
            Layout.leftMargin: 30
            Layout.rightMargin: 30
            visible: false

            textLabel: qsTr(
                           "It seems that either that username is already taken or that your password is not safe enough. A password has these constraints: "
                           + "**at least " + acs.getPasswordMinLength() + " characters long**, "
                           + "**at least " + acs.getPasswordMinNumUpper() + " uppercase letters**, "
                           + "**at least " + acs.getPasswordMinNumLower() + " lowercase letters** and "
                           + "**at least one special character** (" + acs.getPasswordSpecialChars() + ")."
                           )
        }
    }
}
