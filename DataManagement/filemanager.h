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

class FileManager : public QObject
{
    Q_OBJECT

    public:
        FileManager();
        ~FileManager();

    public slots:
        bool addNewFile(QString path, QString oldFilePath);
        bool deleteFile(QString path, QString filename);
};

