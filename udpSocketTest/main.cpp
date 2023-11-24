#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "sendUdp.h"
#include "interfacemanager.h"

static QObject *UserInstance(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    qDebug() << "Creating";

    InterFaceManager *interfacemanager = InterFaceManager::getInstance();

    return interfacemanager;
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    InterFaceManager *interfacemanager = new InterFaceManager();
    qmlRegisterSingletonType<InterFaceManager>("interfacemanager", 1, 0, "InterFaceManager", UserInstance);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);

    engine.load(url); //open main qml to window

    return app.exec();
}
