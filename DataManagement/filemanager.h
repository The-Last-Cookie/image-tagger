#pragma once

#include <QString>
#include <QFile>
#include <QSqlQuery>

#include "settingsmanager.h"

class FileManager
{
    public:
        FileManager();
        ~FileManager();

        bool addNewFile(QString path, QString oldFilePath);
};

