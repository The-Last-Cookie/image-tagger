#pragma once

#include <QObject>
#include <QJsonObject>
#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

class SettingsManager : public QObject
{
    Q_OBJECT

    public:
        explicit SettingsManager(QObject *parent = nullptr);
        ~SettingsManager();

        QJsonObject createDefaultSettingsFile();

    public slots:
        QString getImportMode(QString path);
        void setImportMode(QString path, QString mode);

        QString getTheme(QString path);
        void setTheme(QString path, QString theme);

        bool getEncryption(QString path);
        void setEncryption(QString path, bool encryption);

        QString getLanguage(QString path);
        void setLanguage(QString path, QString language);
};

