#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "sendUdp.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
//    engine.load(url); //open main qml to window
    sendUdp *writeUdpSocket = new sendUdp();
    writeUdpSocket->initSocket();
    writeUdpSocket->writeData();
    return app.exec();
}
