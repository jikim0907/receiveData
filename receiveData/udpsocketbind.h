#ifndef UDPSOCKETBIND_H
#define UDPSOCKETBIND_H

#include <QObject>
#include <QUdpSocket>
#include <QDebug>
#include <QNetworkDatagram>

class UdpSocketBind : public QObject
{
    Q_OBJECT
    public:
        UdpSocketBind(QObject *parent = nullptr);
        QUdpSocket *socket;
        QNetworkDatagram datagram;
        QByteArray buffer;
        void initSocket();
    signals:
        void sendbuffer(QByteArray datagramBuffer);
    public slots:
        void readPendingDatagrams();
};

#endif // UDPSOCKETBIND_H
