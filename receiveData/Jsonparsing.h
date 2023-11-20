#ifndef JSONPARSING_H
#define JSONPARSING_H

//temp
#include <QByteArray>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QObject>
struct skelCoordinates
{
    int x;
    int y;
};

struct skelPart
{
    struct skelCoordinates HeadCoord;
//    struct skelCoordinates BodyCoord;
    struct skelCoordinates MouseCoord;

    struct skelCoordinates rightShoulderCoord;
    struct skelCoordinates leftShoulderCoord;

    struct skelCoordinates rightArmCoord;
    struct skelCoordinates leftArmCoord;

    struct skelCoordinates rightHandCoord;
    struct skelCoordinates leftHandCoord;

    struct skelCoordinates rightThumbCoord;
    struct skelCoordinates leftThumbCoord;

};

class jsonParsing : public QObject
{
    Q_OBJECT

    public:
        jsonParsing(QObject *parent = nullptr);

        QJsonDocument jsonDoc;
        QJsonObject jsonObject;
        struct skelPart skelPartStruct;

//        QByteArray currentBuffer;
        int xPosition ;
        int yPosition ;

    public slots:
        void toJsonDoc(QByteArray buffer);
};

#endif // JSONPARSING_H
