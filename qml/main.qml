// Adapted from https://github.com/KDAB/cxx-qt/blob/v0.5.3/examples/qml_extension_plugin/qml/main.qml
import QtQuick 2.12
import QtQuick.Controls 2.12
import org.openrgb.plugin.rust_sample 1.0

Rectangle {
    color: "lightgray"
    width: 300
    height: 300

    property int animatedValue: 0
    SequentialAnimation on animatedValue {
        loops: Animation.Infinite
        PropertyAnimation { to: 150; duration: 1000 }
        PropertyAnimation { to: 0; duration: 1000 }
    }

    Text {
        anchors.centerIn: parent
        text: parent.animatedValue
    }

    MyObject {
        id: myObject
    }

    Column {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 10

        Label {
            text: "Number: " + myObject.number
        }

        Label {
            text: "String: " + myObject.string
        }

        Button {
            text: "Increment"

            onClicked: myObject.increment()
        }

        Button {
            text: "Reset"

            onClicked: myObject.reset()
        }

        Button {
            text: "Serialize"

            onClicked: seralizedLabel.text = myObject.serialize()
        }

        Label {
            id: seralizedLabel
        }
    }
}
