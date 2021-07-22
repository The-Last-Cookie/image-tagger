import QtQuick 2.0

import "uicomponents" as UIComponents

Item {
    id: root

    Rectangle {
        id: innerContent
        anchors.fill: parent
        color: "brown"

        Text { text:"Here is TagPage" }

        UIComponents.Searchbar {

        }

        UIComponents.FileListView {

        }
    }
}
