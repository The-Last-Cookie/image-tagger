#pragma once

#include <QObject>
#include <QJsonObject>
#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

#include "AccountManagement/accesscontrolsystem.h"
#include "Utils/fileutils.h"

class SettingsManager : public QObject
{
    Q_OBJECT

    public:
        explicit SettingsManager(QObject *parent = nullptr);
        ~SettingsManager();

    public slots:
        static QString getImportMode();
        static void setImportMode(QString mode);

        static QString getTheme();
        static void setTheme(QString theme);

        static bool getEncryption();
        static void setEncryption(bool encryption);

        static QString getLanguage();
        static void setLanguage(QString language);
};

