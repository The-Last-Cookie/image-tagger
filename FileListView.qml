import QtQuick 2.15
import QtQml.Models 2.15

Item {
    id: root

    Rectangle {
        anchors.fill: parent
        border.width: 2
        border.color: "black"

        Component {
            id: fileDelegate

            Item {
                width: grid.cellWidth
                height: grid.cellHeight

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        parent.GridView.view.currentIndex = index
                    }
                }

                Image {
                    //source: name + "." + fileExtension
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Text {
                    text: name + "." + fileExtension
                    wrapMode: Text.WrapAnywhere
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }

        GridView {
            id: grid
            anchors.fill: parent
            cellWidth: 100
            cellHeight: 100
            focus: true
            move: Transition {}

            model: FileViewTemplate {}
            delegate: fileDelegate
            highlight: Rectangle {
                color: "lightsteelblue"
                radius: 5
            }
        }
    }
}
