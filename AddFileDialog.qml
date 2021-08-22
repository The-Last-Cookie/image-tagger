import QtQuick 2.0
import QtQuick.Dialogs 1.3

import DataHandler 1.0

Item {
    id: root

    function open() {
        dialogAddNewFile.open()
    }

    FileDialog {
        id: dialogAddNewFile
        selectMultiple: false
        selectFolder: false
        nameFilters: "*.jpg, *.png"
        folder: shortcuts.home

        onAccepted: {
            if (!fileManager.addNewFile(this.fileUrl)) {
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

    FileManager {
        id: fileManager
    }
}
