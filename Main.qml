import QtQuick
import QtQuick.Window
import QtQuick.Controls 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Button{
        id: myButton
        text: "Click Me"
    }
    client {
            id: client
        }
    server {
        id: server
    }

}
