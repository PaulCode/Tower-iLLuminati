import QtQuick 2.0

Rectangle {
    width: 725
    height: 200
    color: "#00000000"

    Grid {
        columns: 7
        rows: 1
        spacing: 30
        Repeater {
            model: 7
            Grid {
                columns: 4
                rows: 10
                spacing: 5
                Repeater{
                    model: 40
                    Rectangle {
                        width: 15
                        height: 15
                        border.color: "black"
                    }
                }
            }
        }
    }

    Rectangle {
        id: rectangle1
        x: 313
        y: -1
        width: 79
        height: 200
        color: "#00000000"
        border.color: "black"
        border.width: 5
    }
}
