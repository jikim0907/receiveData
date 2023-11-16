#ifndef JSONPARSING_H
#define JSONPARSING_H

//temp
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>

class jsonParsing
{
public:
    jsonParsing();
    void toJsonDoc(const QByteArray &streamData);
    QJsonDocument jsonDoc;
    QJsonObject jsonObject;
};

#endif // JSONPARSING_H
