#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDir>

#include "logger.h"
#include "AccountManagement/accesscontrolsystem.h"
#include "DataManagement/File/filemanager.h"
#include "settingsmanager.h"
#include "DataManagement/Search/searchmanager.h"
#include "DataManagement/Search/searchresult.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    Logger l(QDir::currentPath());
    l.info("Starting application");

    QDir dir;
    if (dir.mkdir("data")) {
        l.warning("Directory data not available. Creating directory data now");
    }
    if (dir.mkdir("logs")) {
        l.warning("Directory logs not available. Creating directory logs now");
    }

    // If not available, create users.json
    QFile file;
    file.setFileName("data/users.json");
    if (file.open(QIODevice::WriteOnly | QIODevice::NewOnly | QIODevice::Text)) {
        QJsonObject jsonObject;
        jsonObject.insert("users", QJsonArray());

        QJsonDocument jsonDoc;
        jsonDoc.setObject(jsonObject);

        QByteArray bytes = jsonDoc.toJson(QJsonDocument::Indented);

        QTextStream out(&file);
        out << bytes;

        l.info("File users.json not available. Creating file users.json now");
    }
    file.close();

    qmlRegisterSingletonInstance<AccessControlSystem>("AccessControlSystem", 1, 0, "AccessControlSystem", &AccessControlSystem::instance());

    qmlRegisterType<FileManager>("DataHandler", 1, 0, "FileManager");
    qmlRegisterType<SettingsManager>("Settings", 1, 0, "SettingsManager");
    qmlRegisterType<SearchManager>("Search", 1, 0, "SearchManager");

    l.info("QML types successfully created");

    l.info("Starting QML engine");
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    int currentExitCode = app.exec();

    AccessControlSystem::instance().logout();

    l.info("Shutting down application");
    return currentExitCode;
}
