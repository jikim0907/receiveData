#ifndef INTERFACEMANAGER_H
#define INTERFACEMANAGER_H

#include "udpsocketbind.h"
#include "Jsonparsing.h"

class interfacemanager : public QObject
{
    Q_OBJECT

    public:
    interfacemanager(QObject *parent = 0);
    static interfacemanager *getInstance();
    static interfacemanager *mInstance;
        jsonParsing* m_jsonParsing;
        UdpSocketBind* m_udpSocketBind;
    };

#endif // INTERFACEMANAGER_H
