import QtQuick 2.15
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import Qt.labs.qmlmodels 1.0

import "qrc:/uicomponents" as UIComponents

Item {
    id: root

    Rectangle {
        id: innerContent
        anchors.fill: parent

        RowLayout {
            id: topRow
            spacing: 5

            UIComponents.Searchbar {
                Layout.leftMargin: 10
                Layout.preferredWidth: 150
                Layout.preferredHeight: 30
                defaultText: qsTr("Search for tags")
            }

            Button {
                text: "Add"
            }

            Button {
                text: "Delete"
            }
        }

        TableView {
            anchors.top: topRow.bottom
            anchors.topMargin: 10
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            columnSpacing: 1
            rowSpacing: 1
            clip: true

            topMargin: header.implicitHeight

            Text {
                id: header
                text: "A table header"
                height: 30
                width: 30
            }

            model: TableModel {
                TableModelColumn { display: "tag" }
                TableModelColumn { display: "description" }
                TableModelColumn { display: "numberOfFiles" }

                rows: [
                    {
                        "tag": "cat",
                        "description": "black",
                        "numberOfFiles": "0"
                    },
                    {
                        "tag": "dog",
                        "description": "brown",
                        "numberOfFiles": "5"
                    },
                    {
                        "tag": "bird",
                        "description": "white",
                        "numberOfFiles": "7"
                    },
                    {
                        "tag": "cat",
                        "description": "black",
                        "numberOfFiles": "3"
                    }
                ]
            }

            delegate: Rectangle {
                implicitWidth: 100
                implicitHeight: 50
                border.width: 1

                Text {
                    text: display
                    anchors.centerIn: parent
                }
            }
        }
    }
}
