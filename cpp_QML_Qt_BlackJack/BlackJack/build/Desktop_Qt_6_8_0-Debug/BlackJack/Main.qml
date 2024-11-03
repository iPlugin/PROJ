import QtQuick 2.15
import QtQuick.Controls 2.15

pragma ComponentBehavior: Bound

ApplicationWindow {
    id: window
    visible: true
    minimumWidth: 800
    minimumHeight: 600
    maximumWidth: 800
    maximumHeight: 600
    title: "BlackJack"

    property int type_cards: 2
    property int type_tables: 3

    property int page_cards: 0
    property int page_tables: 0

    Item {
        focus: true
        Keys.onPressed: (event) => {
            if (event.key === Qt.Key_Enter && window.page_cards != 0 && window.page_tables != 0) {
                stackView.push(secondPage);
            }
            else if (event.key === Qt.Key_Enter && window.page_cards === 0) {
                stackView.push(thirdPage);
            }
            else if (event.key === Qt.Key_Enter && window.page_tables === 0) {
                stackView.push(fourthPage);
            }
            else if (event.key === Qt.Key_Escape) {
                stackView.pop();
            }
        }
    }

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: main
    }

    Component {
        id: main
        Page {
            Image {
                id: main_bckImg
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
            Row {
                id: main_cards
                anchors.horizontalCenter: parent.left
                anchors.horizontalCenterOffset: 100
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: 160
                spacing: 20  // Відстань між кнопками
                Image {
                    id: main_card_left
                    source: "resources/images/left.png"
                    width: 30
                    height: 70
                    fillMode: Image.PreserveAspectFit
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            window.page_cards = (window.page_cards + 1) % (window.type_cards + 1); // +1 Add Icon
                        }
                    }
                }
                Image {
                    id: main_cards_center
                    source: {
                        if (window.page_cards === 0) {
                            return "resources/images/plus.png";
                        }
                        else if (window.page_cards === 1) {
                            return "resources/cards/2_13_1.png";
                        }
                        else if (window.page_cards === 2) {
                            return "resources/cards/1_13_1.png";
                        }
                        // else {
                        //     return "resources/cards/3_13_1.png";
                        // }
                    }
                    width: 30
                    height: 70
                    fillMode: Image.PreserveAspectFit
                }
                Image {
                    id: main_card_right
                    source: "resources/images/right.png"
                    width: 30
                    height: 70
                    fillMode: Image.PreserveAspectFit
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            window.page_cards = (window.page_cards + 1) % (window.type_cards + 1); // +1 Add Icon
                        }
                    }
                }
            }

            Row {
                id: main_tables
                anchors.horizontalCenter: parent.right
                anchors.horizontalCenterOffset: -100
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: 160
                spacing: 20

                Image {
                    id: main_tables_left
                    source: "resources/images/left.png"
                    width: 30
                    height: 70
                    fillMode: Image.PreserveAspectFit
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            window.page_tables = (window.page_tables + 1) % (window.type_tables + 1); // +1 Add Icon
                        }
                    }
                }

                Image {
                    id: main_tables_center
                    source: {
                        if (window.page_tables === 0) {
                            return "resources/images/plus.png";
                        }
                        else if (window.page_tables === 1) {
                            return "resources/tables/1_table.png";
                        }
                        else if (window.page_tables === 2) {
                            return "resources/tables/2_table.jpg";
                        }
                        else if (window.page_tables === 3) {
                            return "resources/tables/3_table.png";
                        }
                        // else {
                        //     return "resources/tables/4_table.png";
                        // }
                    }
                    width: 60
                    height: 70
                    fillMode: Image.PreserveAspectFit
                }

                Image {
                    id: main_tables_right
                    source: "resources/images/right.png"
                    width: 30
                    height: 70
                    fillMode: Image.PreserveAspectFit
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            window.page_tables = (window.page_tables + 1) % (window.type_tables + 1); // +1 Add Icon
                        }
                    }
                }
            }
        }
    }

    Component {
        id: secondPage
        Page {
            Image {
                id: bckImg
                source: {
                    if (window.page_tables === 1) {
                        return "resources/tables/1_table.png";
                    }
                    else if (window.page_tables === 2) {
                        return "resources/tables/2_table.jpg";
                    }
                    else if (window.page_tables === 3) {
                        return "resources/tables/3_table.png";
                    }
                    // else {
                    //     return "resources/tables/4_table.png";
                    // }
                }
                anchors.fill: parent
                fillMode: Image.PreserveAspectCrop
            }
            Text {
                text: "Welcome"
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
        id: thirdPage
        Page {
            Text {
                text: "Welcome add new card"
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
        id: fourthPage
        Page {
            Text {
                text: "Welcome add new table"
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
}
