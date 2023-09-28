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
        text: "Send"
        onClicked: {

                client.sendToServer("Example message");
           }
    }

    TextArea {
           id: textArea
           anchors.centerIn: parent
           wrapMode: TextArea.Wrap

           placeholderText: "Enter your text here..."

           function appendMessage(){
                console.log('Here');
                append("Client: ");
           }
       }
    TextField {
                id: inputLine
                width: parent.width - 40
                y: 100
            }
    Connections{
        target: client
        onG: {
            console.log("Received signal from C++:", client);
            textArea.appendMessage();
        }

    }
}
