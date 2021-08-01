import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

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

            }
        }

        ColumnLayout {

            Text {
                text: qsTr("Theme")
            }

            ComboBox {

            }
        }

        ColumnLayout {

            Text {
                text: qsTr("File encryption")
            }

            CheckBox {
                text: qsTr("Encrypt files")
            }
        }

        ColumnLayout {

            Text {
                text: qsTr("Import method")
            }

            ComboBox {

            }
        }

        ColumnLayout {

            Text {
                text: qsTr("Font size")
            }

            ComboBox {

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
}
