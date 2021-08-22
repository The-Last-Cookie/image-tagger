import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.3
import QtQuick.Window 2.15

import "qrc:/uicomponents" as UIComponents
import DataHandler 1.0

Item {
    id: root

    function open() {
        dialogCreateTag.show()
    }

    Window {
        id: dialogCreateTag
        minimumHeight: 250
        minimumWidth: 250
        title: qsTr("Add a new tag")
        modality: Qt.WindowModal

        ColumnLayout {
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.left: parent.left
            anchors.leftMargin: 10
            spacing: 10

            ColumnLayout {
                id: colName
                spacing: 5

                Text {
                    text: qsTr("Name")
                }

                TextField {
                    id: txtName
                    placeholderText: qsTr("Name")
                }
            }

            ColumnLayout {
                id: colDescription
                spacing: 5

                Text {
                    text: qsTr("Description")
                }

                TextField {
                    id: txtDescription
                    placeholderText: qsTr("Description")
                }
            }

            RowLayout {
                id: btnDialog

                Button {
                    text: qsTr("Cancel")

                    onClicked: {
                        dialogCreateTag.close()
                    }
                }

                Button {
                    text: qsTr("Add new Tag")

                    onClicked: {
                        if (!tagManager.createTag(txtName.text, txtDescription.text)) {
                            dialogTagAlreadyExists.visible = true
                        } else {
                            dialogCreateTag.close()
                        }
                    }
                }
            }

            UIComponents.InfoLabel {
                id: dialogTagAlreadyExists
                Layout.preferredHeight: 60
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignCenter
                Layout.leftMargin: 30
                Layout.rightMargin: 30
                visible: false

                textLabel: qsTr("The tag with this name is not allowed or exists already.")
            }
        }
    }

    TagManager {
        id: tagManager
    }
}
