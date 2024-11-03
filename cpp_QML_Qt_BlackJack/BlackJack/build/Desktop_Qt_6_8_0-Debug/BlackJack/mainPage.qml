import QtQuick 2.15
import QtQuick.Controls 2.15
pragma ComponentBehavior: Bound

ApplicationWindow {
    visible: true
    // width: 800
    // height: 600
    minimumWidth: 800
    minimumHeight: 600
    maximumWidth: 800
    maximumHeight: 600
    title: "BlackJack"


    // Image {
    //     id: bckImg
    //     source: "resources/images/background_1.jpg"
    //     anchors.fill: parent
    //     fillMode: Image.PreserveAspectCrop
    // }
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

    StackView {
            id: stackView
            anchors.fill: parent
            initialItem: mainPage
        }

    Component {
        id: mainPage
        Item {
            Button {
                text: "Перейти на нову сторінку"
                onClicked: stackView.push(secondPage)
            }
        }
    }

    Component {
        id: secondPage
        Item {
            Rectangle {
                color: "lightblue"
                anchors.fill: parent
                Text {
                    text: "Це друга сторінка"
                    anchors.centerIn: parent
                }
            }
        }
    }
}
