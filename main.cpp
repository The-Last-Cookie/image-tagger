#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDir>

#include "logger.h"
#include "accesscontrolsystem.h"

int main(int argc, char *argv[])
{
    Logger l("");
    l.info("Starting application");

    QDir dataDir;
    if (dataDir.mkdir("data")) {
        l.info("Created directory data");
    }

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    AccessControlSystem acs;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("acs", &acs);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
