#ifndef SENDUDP_H
#define SENDUDP_H

#include <QObject>
#include <QString>
#include <QUdpSocket>
#include <QDebug>
#include <QFile>
#include <QByteArray>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <stdio.h>
#include <iostream>

class sendUdp : public QObject
{
    Q_OBJECT
public:
    explicit sendUdp(QObject *parent = nullptr);
    QUdpSocket *socket;
    void initSocket();
    void writeData();
};

#endif // SENDUDP_H
