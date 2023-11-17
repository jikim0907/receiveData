#ifndef UDPSOCKETBIND_H
#define UDPSOCKETBIND_H

#include <QObject>
#include <QUdpSocket>
#include <QDebug>

class UdpSocketBind : public QObject
{
    Q_OBJECT
    public:
        UdpSocketBind(QObject *parent = nullptr);
        QUdpSocket *socket;
        QByteArray buffer;
        QHostAddress sender;
        quint16 senderPort;

        int bindUdp();
    public slots:
        void recieveData();

};

#endif // UDPSOCKETBIND_H
