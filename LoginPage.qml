import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4

Item {
    id: root

    property string defaultName: qsTr("Name")
    property string defaultPassword: qsTr("Password")

    property alias colsLogin: colsLogin
    property alias colsCreate: colsCreate

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
                id: nameLogin
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
                    if (nameLogin.text == defaultName) {
                        nameLogin.text = ""
                    }

                    color = "black"
                }
            }

            TextField {
                id: passwordLogin
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
                    if (passwordLogin.text == defaultName) {
                        passwordLogin.text = ""
                    }

                    color = "black"
                    echoMode = TextInput.Password
                }
            }

            Rectangle {
                id: textCreate
                height: 10
                anchors.top: passwordLogin.bottom
                anchors.left: passwordLogin.left
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
                anchors.right: passwordLogin.right

                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    text: qsTr("Login")
                }

                onClicked: {
                    console.log(nameLogin.text + "\n" + passwordLogin.text)
                }
            }

            Button {
                id: btnLoginGuest
                text: "Login as guest"
                width: parent.width / 3
                height: parent.height / 6
                anchors.horizontalCenter: parent.horizontalCenter

                onClicked: {
                    frame.replace(Qt.resolvedUrl("qrc:/MainPage.qml"))
                }
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
                id: nameCreate
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
                    if (nameCreate.text == defaultName) {
                        nameCreate.text = ""
                    }

                    color = "black"
                }
            }

            TextField {
                id: passwordCreate
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
                    if (passwordCreate.text == defaultName) {
                        passwordCreate.text = ""
                    }

                    color = "black"
                    echoMode = TextInput.Password
                }
            }

            Rectangle {
                id: textLogin
                anchors.top: passwordCreate.bottom
                anchors.left: passwordCreate.left
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
                }
            }
        }
    }
}
