import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    minimumWidth: 800
    minimumHeight: 600
    maximumWidth: 800
    maximumHeight: 600
    title: "BlackJack"

    Item {
        focus: true
        Keys.onPressed: (event) => {
            if (event.key === Qt.Key_Enter) {
                stackView.push(secondPage);
            } else if (event.key === Qt.Key_Escape) {
                stackView.pop();
            }
        }
    }

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: mainPage
    }

    Component {
        id: mainPage
        Page {
            Image {
                id: bckImg
                source: "resources/images/promo.jpg"
                anchors.fill: parent
                fillMode: Image.PreserveAspectCrop
            }
            Text {
                text: "Click enter for start game ..."
                font.family: "Arial Black"
                font.pixelSize: 20
                font.bold: true
                color: "#DAA520"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: 160
            }
        }
    }

    Component {
        id: secondPage
        Page {
            Image {
                id: bckImg
                source: "resources/images/1_table.png"
                anchors.fill: parent
                fillMode: Image.PreserveAspectCrop
            }
            // Text {
            //     text: "Click enter for start game ..."
            //     font.family: "Arial Black"
            //     font.pixelSize: 20
            //     font.bold: true
            //     color: "#DAA520"
            //     anchors.horizontalCenter: parent.horizontalCenter
            //     anchors.verticalCenter: parent.verticalCenter
            //     anchors.verticalCenterOffset: 160
            // }
        }
    }
}
