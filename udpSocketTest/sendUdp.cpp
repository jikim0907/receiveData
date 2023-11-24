#include "sendUdp.h"
sendUdp::sendUdp(QObject *parent):QObject(parent){
//    socket->bind(QHostAddress::LocalHost, 5000);
}

void sendUdp::initSocket(){
    socket = new QUdpSocket(this);
}

void sendUdp::writeData(){

    QFile loadFile(QStringLiteral("/home/jikim/work/jikim_work/receiveData/udpSocketTest/data/message_sample2.json"));
    if(!loadFile.open(QIODevice::ReadOnly)){ //you have to set open mode
        qWarning("Could not open json file to read");
    }
    qDebug() << "send the data!";

    QByteArray loadjsonfile = loadFile.readAll();//TO DO modified
    QJsonDocument JsonFileDoc = QJsonDocument::fromJson(loadjsonfile);
    QJsonObject jsonFileObj = JsonFileDoc.object();
    QJsonValue jsonPoseObj = jsonFileObj.value("data");
    QJsonArray jsonPoseArr = jsonPoseObj.toArray();

    for(int i = 0 ; i <jsonPoseArr.count(); i++){
//        qDebug()<<jsonPoseArr.at(i).toObject(); //{pose:} object send
        QJsonDocument jsonPoseDoc  =QJsonDocument(jsonPoseArr.at(i).toObject());
        QByteArray poseByteArr = jsonPoseDoc.toJson();
        socket->writeDatagram(poseByteArr,QHostAddress::LocalHost, 5000);
    }
}
