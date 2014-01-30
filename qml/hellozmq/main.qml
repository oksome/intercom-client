import QtQuick 2.0
import ZeroSpeaker 1.0

Rectangle {
    width: auto
    height: auto

    ZeroSpeaker {
        id: zerospeaker
    }

    Rectangle {
        id: wakeup_button
        color: '#400000'
        height: parent.height / 2
        width: parent.width

        Text {
            text: qsTr("Wake Up !")
            color: '#FF8000'
            font.pointSize: 24
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                zerospeaker.printMessage("Hello")
                zerospeaker.playMPD()
            }
            onPressed: parent.color = '#600000'
            onReleased: parent.color = '#400000'
        }
    }

    Rectangle {
        id: sleep_button
        color: '#000040'
        height: parent.height / 2
        width: parent.width
        y: parent.height / 2

        Text {
            text: qsTr("Goto sleep...")
            color: '#0080FF'
            font.pointSize: 24
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                zerospeaker.pauseMPD()
            }
            onPressed: parent.color = '#000060'
            onReleased: parent.color = '#000040'
        }
    }
}
