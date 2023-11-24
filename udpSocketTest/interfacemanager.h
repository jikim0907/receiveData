#ifndef INTERFACEMANAGER_H
#define INTERFACEMANAGER_H

#include <QObject>
#include "sendUdp.h"

class InterFaceManager : public QObject
{
    Q_OBJECT
public:
    InterFaceManager(QObject *parent = nullptr);
    static InterFaceManager *getInstance();
    static InterFaceManager *mInstance;

    sendUdp* m_sendUdp;

    Q_INVOKABLE void writeDataToSocket();

};

#endif // INTERFACEMANAGER_H
