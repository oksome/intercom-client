import QtQuick 2.0
import ZeroSpeaker 1.0

Rectangle {
    width: 360
    height: 360

    ZeroSpeaker {
        id: zerospeaker
    }

    Rectangle {
        id: hellobutton
        color: '#FFAAAA'
        height: parent.height / 2
        width: parent.height

        Text {
            text: qsTr("Hello World")
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                zerospeaker.printMessage("Hello")
                zerospeaker.playMPD()
    //            Qt.quit();
            }
        }
    }

    Rectangle {
        id: zerobutton
        color: '#AAAAFF'
        height: parent.height / 2
        width: parent.height
        y: parent.height / 2

        Text {
            text: qsTr("Pause")
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                zerospeaker.pauseMPD()
            }
        }
    }


}
