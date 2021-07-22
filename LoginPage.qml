import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4

import "uicomponents" as UIComponents

Item {
    id: root

    Rectangle {
        width: parent.width / 2
        height: parent.height / 1.5
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        color: "#1f79d3"

        Column {
            id: colsLogin
            width: parent.width
            anchors.topMargin: 30
            anchors.top: parent.top
            spacing: parent.height / 15

            Text {
                text: qsTr("Login")
                font.pointSize: 24
                anchors.horizontalCenter: parent.horizontalCenter
            }

            TextField {
                id: txtLogin
                height: 30
                width: parent.width / 2
                anchors.horizontalCenter: parent.horizontalCenter
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
                id: txtPasswordLogin
                height: 30
                width: parent.width / 2
                anchors.horizontalCenter: parent.horizontalCenter
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

            Rectangle {
                id: switchToCreate
                height: 10
                anchors.top: txtPasswordLogin.bottom
                anchors.left: txtPasswordLogin.left
                anchors.topMargin: 10

                Text {
                    text: qsTr("New here? Create new account")
                    color: "blue"

                    MouseArea {
                        anchors.fill: parent

                        onClicked: {
                            colsLogin.visible = false
                            colsCreate.visible = true
                        }
                    }
                }
            }

            Button {
                id: btnLogin
                width: parent.width / 4
                height: parent.height / 6
                anchors.right: txtPasswordLogin.right

                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    text: qsTr("Login")
                }

                onClicked: {
                    if (!acs.login(txtLogin.text, txtPasswordLogin.text, 0)) {
                        infoUserLoginNotSuccesful.visible = true
                        return
                    }

                    frame.replace(Qt.resolvedUrl("qrc:/MainPage.qml"))
                }
            }

            UIComponents.LabelError {
                id: infoUserLoginNotSuccesful
                height: 20
                anchors.left: parent.left
                anchors.leftMargin: 30
                anchors.right: parent.right
                anchors.rightMargin: 30
                visible: false

                textLabel: qsTr("Username or password not correct.")
            }

            Button {
                id: btnLoginGuest
                text: qsTr("Login as guest")
                width: parent.width / 3
                height: parent.height / 6
                anchors.horizontalCenter: parent.horizontalCenter

                onClicked: {
                    if (acs.login("", "", 1)) {
                        frame.replace(Qt.resolvedUrl("qrc:/MainPage.qml"))
                    }
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
                height: 20
                anchors.left: parent.left
                anchors.leftMargin: 30
                anchors.right: parent.right
                anchors.rightMargin: 30
                visible: false

                textLabel: qsTr("Please be aware that your files will only be available as long as the application is running.")
            }
        }

        Column {
            id: colsCreate
            width: parent.width
            anchors.topMargin: 30
            anchors.top: parent.top
            spacing: parent.height / 15

            visible: false

            Text {
                text: qsTr("Create new account")
                font.pointSize: 24
                anchors.horizontalCenter: parent.horizontalCenter
            }

            TextField {
                id: txtCreate
                height: 30
                width: parent.width / 2
                anchors.horizontalCenter: parent.horizontalCenter
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
                id: txtPasswordCreate
                height: 30
                width: parent.width / 2
                anchors.horizontalCenter: parent.horizontalCenter
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

            Rectangle {
                id: switchToLogin
                anchors.top: txtPasswordCreate.bottom
                anchors.left: txtPasswordCreate.left
                anchors.topMargin: 10

                Text {
                    text: qsTr("Take me back")
                    color: "blue"

                    MouseArea {
                        anchors.fill: parent

                        onClicked: {
                            colsLogin.visible = true
                            colsCreate.visible = false
                        }
                    }
                }
            }

            Button {
                id: btnCreate
                width: parent.width / 3
                height: parent.height / 6
                anchors.horizontalCenter: parent.horizontalCenter

                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    text: qsTr("Create new account")
                }

                onClicked: {
                    if (!acs.createUser(txtCreate.text, txtPasswordCreate.text)) {
                        infoUserCreationNotSuccesful.visible = true
                        return
                    }

                    acs.login(txtCreate.text, txtPasswordCreate.text, 0)
                    frame.replace(Qt.resolvedUrl("qrc:/MainPage.qml"))
                }
            }

            UIComponents.LabelError {
                id: infoUserCreationNotSuccesful
                height: 60
                anchors.left: parent.left
                anchors.leftMargin: 30
                anchors.right: parent.right
                anchors.rightMargin: 30
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
}
