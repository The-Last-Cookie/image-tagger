import QtQuick 2.12
import QtQuick.Controls 2.12

import "uicomponents" as UIComponents

Item {
    id: root

    Rectangle {
        id: content
        anchors.fill: parent

        Rectangle {
            id: tagListing

            Text { text:"Here is MainPage" }
        }

        Rectangle {
            id: filesListing

            UIComponents.Searchbar {

            }

            UIComponents.FileListView {

            }
        }
    }
}
