import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import interfacemanager 1.0
Window {
    width: 500
    height: 500
    visible: true
    title: qsTr("UDP Socket")

    Button{
        anchors.centerIn: parent
        width:parent.width/2
        height: parent.height/2
        text:"write the Data!"
        onClicked:{
            InterFaceManager.writeDataToSocket();
            console.log("clicked");
        }
    }
}
