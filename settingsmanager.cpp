#include "settingsmanager.h"

SettingsManager::SettingsManager(QObject *parent) : QObject(parent)
{

}

SettingsManager::~SettingsManager()
{

}

QString SettingsManager::getImportMode()
{
    QString settingsPath = "data/" + AccessControlSystem::instance().getSessionPath() + "/settings.json";
    QJsonObject jsonObject = FileUtils::readJson(settingsPath);

    QString importMode = jsonObject["import_mode"].toString();
    return importMode;
}

void SettingsManager::setImportMode(QString mode)
{
    QString settingsPath = "data/" + AccessControlSystem::instance().getSessionPath() + "/settings.json";
    QJsonObject jsonObject = FileUtils::readJson(settingsPath);

    jsonObject.insert("import_mode", mode);

    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObject);
    QFile file;
    file.setFileName(settingsPath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QByteArray bytes = jsonDoc.toJson(QJsonDocument::Indented);

        QTextStream out(&file);
        out << bytes;
    }
    file.close();
}

QString SettingsManager::getTheme()
{
    QString settingsPath = "data/" + AccessControlSystem::instance().getSessionPath() + "/settings.json";
    QJsonObject jsonObject = FileUtils::readJson(settingsPath);

    QString theme = jsonObject["theme"].toString();
    return theme;
}

void SettingsManager::setTheme(QString theme)
{
    QString settingsPath = "data/" + AccessControlSystem::instance().getSessionPath() + "/settings.json";
    QJsonObject jsonObject = FileUtils::readJson(settingsPath);

    jsonObject.insert("theme", theme);

    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObject);
    QFile file;
    file.setFileName(settingsPath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QByteArray bytes = jsonDoc.toJson(QJsonDocument::Indented);

        QTextStream out(&file);
        out << bytes;
    }
    file.close();
}

bool SettingsManager::getEncryption()
{
    QString settingsPath = "data/" + AccessControlSystem::instance().getSessionPath() + "/settings.json";
    QJsonObject jsonObject = FileUtils::readJson(settingsPath);

    bool encryption = jsonObject["encryption"].toBool();
    return encryption;
}

void SettingsManager::setEncryption(bool encryption)
{
    QString settingsPath = "data/" + AccessControlSystem::instance().getSessionPath() + "/settings.json";
    QJsonObject jsonObject = FileUtils::readJson(settingsPath);

    jsonObject.insert("encryption", encryption);

    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObject);
    QFile file;
    file.setFileName(settingsPath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QByteArray bytes = jsonDoc.toJson(QJsonDocument::Indented);

        QTextStream out(&file);
        out << bytes;
    }
    file.close();
}

QString SettingsManager::getLanguage()
{
    QString settingsPath = "data/" + AccessControlSystem::instance().getSessionPath() + "/settings.json";
    QJsonObject jsonObject = FileUtils::readJson(settingsPath);

    QString language = jsonObject["language"].toString();
    return language;
}

void SettingsManager::setLanguage(QString language)
{
    QString settingsPath = "data/" + AccessControlSystem::instance().getSessionPath() + "/settings.json";
    QJsonObject jsonObject = FileUtils::readJson(settingsPath);

    jsonObject.insert("language", language);

    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObject);
    QFile file;
    file.setFileName(settingsPath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QByteArray bytes = jsonDoc.toJson(QJsonDocument::Indented);

        QTextStream out(&file);
        out << bytes;
    }
    file.close();
}
