#include "settingsmanager.h"

SettingsManager::SettingsManager()
{

}

SettingsManager::~SettingsManager()
{

}

QJsonObject SettingsManager::createDefaultSettingsFile()
{
    QJsonObject settings;
    settings.insert("theme", "white");
    settings.insert("import_mode", "move");

    return settings;
}

QString SettingsManager::getImportMode(QString path)
{
    QFile file;
    file.setFileName("data/" + path + "/settings.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString data = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();

    QString importMode = jsonObject["import_mode"].toString();
    return importMode;
}

void SettingsManager::setImportMode(QString path, QString mode)
{

}
