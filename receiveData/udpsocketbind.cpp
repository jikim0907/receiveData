#include "udpsocketbind.h"

UdpSocketBind::UdpSocketBind(QObject *parent)
    : QObject(parent)
{
    this->bindUdp();
}

int UdpSocketBind::bindUdp(){
    socket = new QUdpSocket();
    socket->bind(QHostAddress::LocalHost, 5000);

    //when sokcet Port receive stream data readData slot is called
    connect(socket, SIGNAL(readyRead()), this, SLOT(recieveData()));
    return 0;
}

void UdpSocketBind::recieveData(){
    buffer;
    buffer.resize(socket->pendingDatagramSize());

    /*Receive stream data and save those in buffer's data,
    We can use to refer the json data in buffer data*/
    socket->readDatagram(buffer.data(), buffer.size(),
                         &sender, &senderPort);
}
