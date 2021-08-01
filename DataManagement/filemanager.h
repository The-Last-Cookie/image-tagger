#pragma once

#include <QString>
#include <QStringRef>
#include <QFile>
#include <QDir>
#include <QSqlQuery>
#include <QVariant>

#include "settingsmanager.h"

class FileManager
{
    public:
        FileManager();
        ~FileManager();

        bool addNewFile(QString path, QString oldFilePath);
};

