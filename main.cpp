#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDir>

#include "logger.h"
#include "AccountManagement/accesscontrolsystem.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    Logger l(QDir::currentPath());
    l.info("Starting application");

    QDir dir;
    if (dir.mkdir("data")) {
        l.info("Created directory data");
    }
    if (dir.mkpath("logs")) {
        l.info("Created directory logs");
    }

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

    int currentExitCode = app.exec();

    acs.logout();

    l.info("Shutting down application");
    return currentExitCode;
}
