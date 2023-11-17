#include "Interfacemanager.h"
#include <iostream>
#include <string.h>
interfacemanager* interfacemanager::mInstance = NULL;

interfacemanager::interfacemanager(QObject *parent)
    :QObject(parent)
{
    mInstance = this;
    m_jsonParsing = new jsonParsing;
    m_udpSocketBind = new UdpSocketBind;
    int bindStatus = m_udpSocketBind->bindUdp();
    if(!bindStatus){
        connect(m_udpSocketBind->socket, SIGNAL(readyRead()),m_jsonParsing, SLOT(toJsonDoc(const QByteArray &refBuffer)));
    }
}

interfacemanager *interfacemanager::getInstance()
{
    std::cout << "getinstance"<<mInstance <<endl;
    return mInstance;
}
