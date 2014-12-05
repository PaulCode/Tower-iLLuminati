import QtQuick 2.3
import QtQuick.Controls 1.2

Rectangle {
    width: 415
    height: 995
    Grid {
        id: towerGrid
        rows: 20
        columns: 12
        spacing: 5
        Repeater {
            model: 240
            Rectangle {
                id: window
                width: 25
                height: 25
                color: "grey"
                border.width: 1
                border.color: "black"
                MouseArea {
                    acceptedButtons: Qt.LeftButton | Qt.RightButton
                    anchors.fill: parent
                    onClicked: {
                        if(mouse.button == Qt.RightButton){
                            parent.color = "grey"
                        } else {
                            parent.color = currentColor.colorToString()
                        }
                    }
                }
            }
        }
    }
}
