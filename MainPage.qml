import QtQuick 2.12
import QtQuick.Controls 2.12

import "uicomponents" as UIComponents

Item {
    id: root

    UIComponents.Drawer {
        id: sidebar
        width: 20
        height: parent.height

        Label {
            text: "Aa"
            font.pixelSize: 96
            anchors.fill: parent
            verticalAlignment: Label.AlignVCenter
            horizontalAlignment: Label.AlignHCenter
        }
    }

    StackView {
        id: content
        initialItem: homepage
        anchors.fill: parent

        HomePage {
            id: homepage

        }

        TagPage {
            id: tagpage

            UIComponents.Searchbar {

            }

            UIComponents.FileListView {

            }
        }

        GroupPage {
            id: grouppage

        }

        AuthorPage {
            id: authorpage

        }

        AccountPage {
            id: accountpage

        }

        SettingsPage {
            id: settingspage

        }
    }
}
