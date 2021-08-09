import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.12
import Qt.labs.settings 1.0

import AccessControlSystem 1.0
import Settings 1.0

Item {
    id: root

    ColumnLayout {
        spacing: 0
        anchors.fill: parent
        anchors.leftMargin: 10

        ColumnLayout {

            Text {
                text: qsTr("Language")
            }

            ComboBox {
                currentIndex: 0
                model: ListModel {
                    id: languages
                    ListElement { text: "English" }
                    ListElement { text: "Deutsch" }
                    ListElement { text: "Français" }
                }

                onCurrentIndexChanged: {
                    //settings.setLanguage(AccessControlSystem.getSessionPath(), Language.getCode(languages.get(currentIndex).text))
                }

                enabled: false
            }
        }

        ColumnLayout {

            Text {
                text: qsTr("Theme")
            }

            ComboBox {
                model: [qsTr("White"), qsTr("Dark")]

                enabled: false
            }
        }

        ColumnLayout {

            Text {
                text: qsTr("File encryption")
            }

            CheckBox {
                id: encryption
                text: qsTr("Encrypt files")

                onCheckStateChanged: {
                    settings.setEncryption(AccessControlSystem.getSessionPath(), encryption.checked)
                }

                enabled: false
            }
        }

        ColumnLayout {

            Text {
                text: qsTr("Import method")
            }

            ComboBox {
                model: [qsTr("Move"), qsTr("Copy")]

                enabled: false
            }
        }

        ColumnLayout {

            Text {
                text: qsTr("App information")
            }

            Text {
                text: qsTr("Version: 0.1")
            }

            Text {
                text: qsTr("Made by The-Last-Cookie")
            }

            Text {
                text: qsTr("Github: github.com/The-Last-Cookie")
            }
        }
    }

    SettingsManager {
        id: settings
    }
}
