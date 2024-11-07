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

    property int page_cards: 1
    property int page_tables: 3

    property int balance: 1000
    property int bet: 0

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
        initialItem: secondPage
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
                        else {
                            return "resources/cards/" + window.page_cards + "_13_1.png";
                        }
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
                        else {
                            return "resources/tables/" + window.page_tables + "_table.png";
                        }
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
                source: "resources/tables/" + window.page_tables + "_table.png"
                anchors.fill: parent
                fillMode: Image.PreserveAspectCrop
            }

            Text {
                text: "Balance: " + window.balance + "$ | Bet: " + window.bet
                font.pixelSize: 20
                font.bold: true
                anchors.bottom: parent.bottom
                anchors.horizontalCenter: parent.horizontalCenter
            }




            // Image {
            //     id: buttonPlay
            //     source: "resources/images/play-round.png"
            //     width: 70
            //     height: 70
            //     anchors.centerIn: parent
            //     visible: true
            //     MouseArea {
            //         anchors.fill: parent
            //         onClicked: {
            //             buttonPlay.visible = false;
            //             leftCard.visible = true;
            //             flyLeftCard.start();
            //             hit.visible = true;
            //             stand.visible = true;
            //         }
            //     }
            // }


            Image {
                id: stand
                source: "resources/images/stand.png"
                width: 50
                height: 50
                visible: false
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.margins: 50  // Відстань від правого та нижнього краю
            }

            Image {
                id: hit
                source: "resources/images/hit.png"
                width: 50
                height: 50
                visible: false
                anchors.right: stand.right
                anchors.bottom: stand.top
                anchors.bottomMargin: 20  // Відстань від правого та нижнього краю
            }

            Image {
                id: play
                source: "resources/images/joker.png"
                width: 50
                height: 50
                visible: false
                anchors.right: return_chip.right
                anchors.bottom: return_chip.top
                anchors.bottomMargin: 20  // Відстань від правого та нижнього краю
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        // buttonPlay.visible = false;
                        leftCard.visible = true;
                        flyLeftCard.start();
                        hit.visible = true;
                        stand.visible = true;
                        chip10.visible = false;
                        chip25.visible = false;
                        chip50.visible = false;
                        chip100.visible = false;
                        play.visible = false;
                        return_chip.visible = false;
                    }
                }
            }

            Image {
                id: return_chip
                source: "resources/images/return.png"
                width: 50
                height: 50
                visible: false
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.margins: 50
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        play.visible = false
                        return_chip.visible = false
                        window.bet = 0
                        window.balance = 1000
                    }
                }
            }

            Image {
                id: chip10
                source: "resources/images/10-chip.png"
                width: 50
                height: 50
                visible: true
                anchors.left: parent.left
                anchors.bottom: parent.bottom
                anchors.margins: 10  // Відстань від правого та нижнього краю
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        window.bet += 10
                        window.balance -= 10
                        play.visible = true
                        return_chip.visible = true
                    }
                }
            }

            Image {
                id: chip25
                source: "resources/images/25-chip.png"
                width: 50
                height: 50
                visible: true
                anchors.right: chip10.right
                anchors.bottom: chip10.top
                anchors.bottomMargin: 10
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        window.bet += 25
                        window.balance -= 25
                        play.visible = true
                        return_chip.visible = true
                    }
                }
            }

            Image {
                id: chip50
                source: "resources/images/50-chip.png"
                width: 50
                height: 50
                visible: true
                anchors.right: chip25.right
                anchors.bottom: chip25.top
                anchors.bottomMargin: 10
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        window.bet += 50
                        window.balance -= 50
                        play.visible = true
                        return_chip.visible = true
                    }
                }
            }

            Image {
                id: chip100
                source: "resources/images/100-chip.png"
                width: 50
                height: 50
                visible: true
                anchors.right: chip50.right
                anchors.bottom: chip50.top
                anchors.bottomMargin: 10
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        window.bet += 100
                        window.balance -= 100
                        play.visible = true
                        return_chip.visible = true
                    }
                }
            }


            Item {
            id: cardAnimationContainer
            width: window.width
            height: window.height

            // Перша карта зліва
            Image {
                id: leftCard
                source: "resources/cards/" + window.page_cards + "_0_0.png"
                x: -width  // початкове розташування за межами лівого краю
                y: window.height / 2 - height - 100
                width: 70
                height: 120
                visible: false  // приховано до початку анімації

                PropertyAnimation {
                    id: flyLeftCard
                    target: leftCard
                    properties: "x"
                    duration: 200
                    to: window.width / 2 - 85  // кінцеве положення карти по горизонталі
                    onFinished: {
                        leftCard.source = "resources/cards/" + window.page_cards + "_10_2.png";
                        // Після завершення анімації першої карти, починаємо анімацію другої карти
                        rightCard.visible = true;
                        flyRightCard.start(); // Запуск анімації для правої карти
                    }
                }
            }

            // Друга карта з правого боку
            Image {
                id: rightCard
                source: "resources/cards/" + window.page_cards + "_0_0.png"
                x: window.width  // початкове розташування за межами правого краю
                y: window.height / 2 - height - 100
                width: 70
                height: 120
                visible: false

                PropertyAnimation {
                    id: flyRightCard
                    target: rightCard
                    properties: "x"
                    duration: 200
                    to: window.width / 2 + 15  // кінцеве положення карти по горизонталі
                    onFinished: {
                        // rightCard.source = "resources/cards/" + window.page_cards + "_6_1.png";
                        // Після завершення анімації правої карти, починаємо анімацію третьої карти
                        leftCard2.visible = true;
                        flyLeftCard2.start(); // Запуск анімації для лівої карти 2
                    }
                }
            }
        }

        Item {
            id: cardAnimationContainer2
            width: window.width
            height: window.height

            // Перша карта зліва
            Image {
                id: leftCard2
                source: "resources/cards/" + window.page_cards + "_0_0.png"
                x: -width  // початкове розташування за межами лівого краю
                y: window.height / 2 - height + 250
                width: 70
                height: 120
                visible: false  // приховано до початку анімації

                PropertyAnimation {
                    id: flyLeftCard2
                    target: leftCard2
                    properties: "x"
                    duration: 200
                    to: window.width / 2 - 85  // кінцеве положення карти по горизонталі
                    onFinished: {
                        leftCard2.source = "resources/cards/" + window.page_cards + "_11_3.png";
                        // Після завершення анімації лівої карти 2, починаємо анімацію правої карти 2
                        rightCard2.visible = true;
                        flyRightCard2.start(); // Запуск анімації для правої карти 2
                    }
                }
            }

            // Друга карта з правого боку
            Image {
                id: rightCard2
                source: "resources/cards/" + window.page_cards + "_0_0.png"
                x: window.width  // початкове розташування за межами правого краю
                y: window.height / 2 - height + 250
                width: 70
                height: 120
                visible: false

                PropertyAnimation {
                    id: flyRightCard2
                    target: rightCard2
                    properties: "x"
                    duration: 200
                    to: window.width / 2 + 15  // кінцеве положення карти по горизонталі
                    onFinished: {
                        rightCard2.source = "resources/cards/" + window.page_cards + "_6_1.png";
                    }
                }
            }
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
