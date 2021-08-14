#pragma once

#include <QObject>
#include <QString>
#include <QStringRef>
#include <QFile>
#include <QDir>
#include <QSqlQuery>
#include <QVariant>

#include "settingsmanager.h"
#include "dateutils.h"
#include "databasemanager.h"
#include "AccountManagement/accesscontrolsystem.h"

class FileManager : public QObject
{
    Q_OBJECT

    public:
        explicit FileManager(QObject *parent = nullptr);
        ~FileManager();

    public slots:
        bool addNewFile(QString oldFilePath);
        bool deleteFile(int fileId, QString name, QString extension);
};
