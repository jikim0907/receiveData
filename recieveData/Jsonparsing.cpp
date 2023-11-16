#include "Jsonparsing.h"

jsonParsing::jsonParsing()
{

}


void jsonParsing::toJsonDoc(const QByteArray &streamData){
    jsonDoc = QJsonDocument::fromJson(streamData);
    jsonObject = jsonDoc.object();

    QJsonValue jsonObjPose = jsonObject.value("pose");
    QJsonArray coordArray = jsonObjPose.toArray();

    for(int i = 0; coordArray.count();i++){
        QJsonObject coorObj = coordArray.at(i).toObject();
        int xPosition = coorObj["x"];
        int yPosition = coorObj["y"];

        switch (i) {
        case 0:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        case 13:
            break;
        case 14:
            break;
        case 15:
            break;
        case 16:
            break;
        case 21:
            break;
        case 22:
            break;

        default:
            break;
        }
    }

}
