import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.3

import "uicomponents" as UIComponents
import DataHandler 1.0

Item {
    id: root

    RowLayout {
        spacing: 0
        anchors.fill: parent

        Rectangle {
            id: tagListing
            Layout.fillHeight: true
            Layout.preferredWidth: parent.width * 0.3

            Text {
                text: "**Tags**\n\nflower 20\n\nmountain 12\n\n"
                textFormat: Text.MarkdownText
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 10
                anchors.topMargin: 10
            }

            Text {
                text: "**Information**\n\nName: file.png\n\nAuthor: Burger\n\nFile extension: jpg"
                textFormat: Text.MarkdownText
                anchors.left: parent.left
                anchors.bottom: parent.bottom
                anchors.leftMargin: 10
                anchors.bottomMargin: 10
            }
        }

        Rectangle {
            id: filesListing
            Layout.fillHeight: true
            Layout.fillWidth: true

            RowLayout {
                id: actionMenu
                anchors.right: parent.right
                anchors.left: parent.left
                spacing: 5

                UIComponents.Searchbar {
                    Layout.fillWidth: true
                    Layout.minimumWidth: 150
                    Layout.minimumHeight: 30
                    Layout.leftMargin: 10
                    defaultText: qsTr("Search")
                }

                RowLayout {
                    spacing: 5
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignRight

                    Button {
                        text: "Add file"
                        Layout.minimumWidth: 10

                        onClicked: {
                            dialogAddNewFile.open()
                        }
                    }

                    Button {
                        text: "Add tag"
                        Layout.minimumWidth: 10
                    }
                }
            }

            UIComponents.FileListView {
                anchors.top: actionMenu.bottom
                anchors.topMargin: 10
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
            }
        }
    }

    FileManager {
        id: fileManager
    }

    FileDialog {
        id: dialogAddNewFile
        selectMultiple: false
        selectFolder: false
        nameFilters: "*.jpg, *.png"
        folder: shortcuts.home

        onAccepted: {
            if (!fileManager.addNewFile(acs.getSessionPath(), this.fileUrl)) {
                dialogFileAlreadyExists.open()
            }
        }
    }

    MessageDialog {
        id: dialogFileAlreadyExists
        icon: StandardIcon.Warning
        title: qsTr("Can't add file")
        text: qsTr("The file that you want to add, already exists.")
    }
}
