#include "Interfacemanager.h"
#include <iostream>
#include <string.h>
#include <QDebug>
interfacemanager* interfacemanager::mInstance = NULL;

interfacemanager::interfacemanager(QObject *parent)
    :QObject(parent)
{
    mInstance = this;
    m_jsonParsing = new jsonParsing;
    m_udpSocketBind = new UdpSocketBind;
    m_udpSocketBind->initSocket();
    connect(m_udpSocketBind, SIGNAL(sendbuffer(QByteArray)),
                m_jsonParsing, SLOT(toJsonDoc(QByteArray)));
}

interfacemanager *interfacemanager::getInstance()
{
    std::cout << "getinstance"<<mInstance <<std::endl;
    return mInstance;
}
