#include "settingsmanager.h"

SettingsManager::SettingsManager(QObject *parent) : QObject(parent)
{

}

SettingsManager::~SettingsManager()
{

}

QString SettingsManager::getImportMode()
{
    QFile file;
    file.setFileName("data/" + AccessControlSystem::instance().getSessionPath() + "/settings.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString data = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();

    QString importMode = jsonObject["import_mode"].toString();
    return importMode;
}

void SettingsManager::setImportMode(QString mode)
{
    QFile file;
    file.setFileName("data/" + AccessControlSystem::instance().getSessionPath() + "/settings.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString data = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();

    jsonObject.insert("import_mode", mode);

    jsonDoc.setObject(jsonObject);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QByteArray bytes = jsonDoc.toJson(QJsonDocument::Indented);

        QTextStream out(&file);
        out << bytes;
    }
    file.close();
}

QString SettingsManager::getTheme()
{
    QFile file;
    file.setFileName("data/" + AccessControlSystem::instance().getSessionPath() + "/settings.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString data = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();

    QString theme = jsonObject["theme"].toString();
    return theme;
}

void SettingsManager::setTheme(QString theme)
{
    QFile file;
    file.setFileName("data/" + AccessControlSystem::instance().getSessionPath() + "/settings.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString data = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();

    jsonObject.insert("theme", theme);

    jsonDoc.setObject(jsonObject);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QByteArray bytes = jsonDoc.toJson(QJsonDocument::Indented);

        QTextStream out(&file);
        out << bytes;
    }
    file.close();
}

bool SettingsManager::getEncryption()
{
    QFile file;
    file.setFileName("data/" + AccessControlSystem::instance().getSessionPath() + "/settings.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString data = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();

    bool encryption = jsonObject["encryption"].toBool();
    return encryption;
}

void SettingsManager::setEncryption(bool encryption)
{
    QFile file;
    file.setFileName("data/" + AccessControlSystem::instance().getSessionPath() + "/settings.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString data = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();

    jsonObject.insert("encryption", encryption);

    jsonDoc.setObject(jsonObject);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QByteArray bytes = jsonDoc.toJson(QJsonDocument::Indented);

        QTextStream out(&file);
        out << bytes;
    }
    file.close();
}

QString SettingsManager::getLanguage()
{
    QFile file;
    file.setFileName("data/" + AccessControlSystem::instance().getSessionPath() + "/settings.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString data = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();

    QString language = jsonObject["language"].toString();
    return language;
}

void SettingsManager::setLanguage(QString language)
{
    QFile file;
    file.setFileName("data/" + AccessControlSystem::instance().getSessionPath() + "/settings.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString data = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();

    jsonObject.insert("language", language);

    jsonDoc.setObject(jsonObject);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QByteArray bytes = jsonDoc.toJson(QJsonDocument::Indented);

        QTextStream out(&file);
        out << bytes;
    }
    file.close();
}
