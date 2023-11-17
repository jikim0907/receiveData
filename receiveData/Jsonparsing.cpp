#include "Jsonparsing.h"

jsonParsing::jsonParsing(QObject *parent)
    : QObject(parent){}

void jsonParsing::toJsonDoc(const QByteArray &refBuffer){
    jsonDoc = QJsonDocument::fromJson(refBuffer);
    jsonObject = jsonDoc.object();

    QJsonValue jsonObjPose = jsonObject.value("pose");
    QJsonArray coordArray = jsonObjPose.toArray();

    for(int i = 0; coordArray.count();i++){
        QJsonObject coorObj = coordArray.at(i).toObject();

        xPosition = coorObj["x"].toInt();
        yPosition = coorObj["y"].toInt();
        switch (i) {
            case 0:
                skelPartStruct.HeadCoord.x = xPosition;
                skelPartStruct.HeadCoord.y = yPosition;
                break;
            case 10:
                skelPartStruct.MouseCoord.x = xPosition;
                skelPartStruct.MouseCoord.y = yPosition;
                break;
            case 11:
                skelPartStruct.rightShoulderCoord.x = xPosition;
                skelPartStruct.rightShoulderCoord.y = yPosition;
                break;
            case 12:
                skelPartStruct.leftShoulderCoord.x = xPosition;
                skelPartStruct.leftShoulderCoord.y = yPosition;
                break;
            case 13:
                skelPartStruct.rightArmCoord.x = xPosition;
                skelPartStruct.rightArmCoord.y = yPosition;
                break;
            case 14:
                skelPartStruct.leftArmCoord.x = xPosition;
                skelPartStruct.leftArmCoord.y = yPosition;
                break;
            case 15:
                skelPartStruct.rightHandCoord.x = xPosition;
                skelPartStruct.rightHandCoord.y = yPosition;
                break;
            case 16:
                skelPartStruct.leftHandCoord.x = xPosition;
                skelPartStruct.leftHandCoord.y = yPosition;
                break;
            case 21:
                skelPartStruct.rightThumbCoord.x = xPosition;
                skelPartStruct.rightThumbCoord.y = yPosition;
                break;
            case 22:
                skelPartStruct.leftThumbCoord.x = xPosition;
                skelPartStruct.leftThumbCoord.y = yPosition;
                break;
            default:
                break;
        }
    }
}
