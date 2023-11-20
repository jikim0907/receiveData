#include "sendUdp.h"
sendUdp::sendUdp(QObject *parent):QObject(parent){
//    socket->bind(QHostAddress::LocalHost, 5000);
}

void sendUdp::initSocket(){
    socket = new QUdpSocket(this);
}

void sendUdp::writeData(){

    QFile loadFile(QStringLiteral("/home/jikim/work/jikim_work/receiveData/udpSocketTest/data/testpose.json"));
    if(!loadFile.open(QIODevice::ReadOnly)){ //you have to set open mode
        qWarning("Could not open json file to read");
    }
    qDebug() << "send the data!";
    QByteArray loadData = loadFile.readAll();//TO DO modified
//    QJsonDocument loadDoc = QJsonDocument::fromJson(loadData);
//    QByteArray jsonData = loadData.toJson();

//    QByteArray jsonData = loadDoc.toJson();
//    socket->writeDatagram(jsonData,QHostAddress::LocalHost, 5000);

    socket->writeDatagram(loadData,QHostAddress::LocalHost, 5000);
}
