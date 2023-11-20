#include "udpsocketbind.h"
UdpSocketBind::UdpSocketBind(QObject *parent): QObject(parent){}

void UdpSocketBind::initSocket(){
    socket = new QUdpSocket();
    socket->bind(QHostAddress::LocalHost, 5000); //To to bind to HostAddress to receive the data
    qDebug() << "client UDP socket has been created";

    connect(socket, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
}

void UdpSocketBind::readPendingDatagrams(){

//    QHostAddress sender;
//    quint16 senderPort;

    while (socket->hasPendingDatagrams()) {
        datagram = socket->receiveDatagram();

        buffer.resize(socket->pendingDatagramSize());
        buffer = datagram.data();

        emit sendbuffer(buffer);
    }

//    socket->readDatagram(buffer.data(), buffer.size(),
//                         &sender, &senderPort);

}
