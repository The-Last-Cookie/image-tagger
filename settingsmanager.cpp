#include "settingsmanager.h"

SettingsManager::SettingsManager(QObject *parent) : QObject(parent)
{

}

SettingsManager::~SettingsManager()
{

}

QJsonObject SettingsManager::createDefaultSettingsFile()
{
    QJsonObject settings;
    settings.insert("language", "en");
    settings.insert("theme", "white");
    settings.insert("encryption", true);
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
    QFile file;
    file.setFileName("data/" + path + "/settings.json");
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

QString SettingsManager::getTheme(QString path)
{
    QFile file;
    file.setFileName("data/" + path + "/settings.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString data = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();

    QString theme = jsonObject["theme"].toString();
    return theme;
}

void SettingsManager::setTheme(QString path, QString theme)
{
    QFile file;
    file.setFileName("data/" + path + "/settings.json");
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

bool SettingsManager::getEncryption(QString path)
{
    QFile file;
    file.setFileName("data/" + path + "/settings.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString data = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();

    bool encryption = jsonObject["encryption"].toBool();
    return encryption;
}

void SettingsManager::setEncryption(QString path, bool encryption)
{
    QFile file;
    file.setFileName("data/" + path + "/settings.json");
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

QString SettingsManager::getLanguage(QString path)
{
    QFile file;
    file.setFileName("data/" + path + "/settings.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString data = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();

    QString language = jsonObject["language"].toString();
    return language;
}

void SettingsManager::setLanguage(QString path, QString language)
{
    QFile file;
    file.setFileName("data/" + path + "/settings.json");
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
