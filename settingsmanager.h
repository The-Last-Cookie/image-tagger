#pragma once

#include <QObject>
#include <QJsonObject>
#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

#include "AccountManagement/accesscontrolsystem.h"

class SettingsManager : public QObject
{
    Q_OBJECT

    public:
        explicit SettingsManager(QObject *parent = nullptr);
        ~SettingsManager();

    public slots:
        QString getImportMode();
        void setImportMode(QString mode);

        QString getTheme();
        void setTheme(QString theme);

        bool getEncryption();
        void setEncryption(bool encryption);

        QString getLanguage();
        void setLanguage(QString language);
};

