#pragma once

#include <QJsonObject>
#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

class SettingsManager
{
    public:
        SettingsManager();
        ~SettingsManager();

        QJsonObject createDefaultSettingsFile();

        QString getImportMode(QString path);
        void setImportMode(QString path, QString mode);
};

