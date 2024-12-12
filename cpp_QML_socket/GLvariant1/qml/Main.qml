Component {
    id: secondPage
    Page {
        Image {
            id: bckImg
            source: "resources/tables/" + window.page_tables + "_table.png"
            anchors.fill: parent
            fillMode: Image.PreserveAspectCrop
        }
        Image {
            id: buttonPlay
            source: "resources/images/play-round.png"
            width: 70
            height: 70
            anchors.centerIn: parent
            visible: true
            // Оголошення таймерів на рівні компонента
            Timer {
                id: timer1
                interval: 500
                running: false
                repeat: false
                onTimeout: {
                    leftCard.visible = true;
                    flyLeftCard.start();
                    // Запуск наступного таймера
                    timer2.start();
                }
            }
            
            Timer {
                id: timer2
                interval: 500
                running: false
                repeat: false
                onTimeout: {
                    rightCard.visible = true;
                    flyRightCard.start();
                    // Запуск наступного таймера
                    timer3.start();
                }
            }
            
            Timer {
                id: timer3
                interval: 500
                running: false
                repeat: false
                onTimeout: {
                    leftCard2.visible = true;
                    flyLeftCard2.start();
                    // Запуск наступного таймера
                    timer4.start();
                }
            }
            
            Timer {
                id: timer4
                interval: 500
                running: false
                repeat: false
                onTimeout: {
                    rightCard2.visible = true;
                    flyRightCard2.start();
                }
            }
            
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    buttonPlay.visible = false;
                    // Запуск першого таймера
                    timer1.start();
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
                    duration: 1000
                    to: window.width / 2 - 85  // кінцеве положення карти по горизонталі
                    onFinished: {
                        leftCard.source = "resources/cards/" + window.page_cards + "_10_2.png";
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
                    duration: 1000
                    to: window.width / 2 + 15  // кінцеве положення карти по горизонталі
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
                    duration: 1000
                    to: window.width / 2 - 85  // кінцеве положення карти по горизонталі
                    onFinished: {
                        leftCard2.source = "resources/cards/" + window.page_cards + "_11_3.png";
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
                        duration: 1000
                        to: window.width / 2 + 15  // кінцеве положення карти по горизонталі
                        onFinished: {
                            rightCard2.source = "resources/cards/" + window.page_cards + "_6_1.png";
                        }
                    }
                }
            }
        }
    }
