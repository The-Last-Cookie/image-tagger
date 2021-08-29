#pragma once

#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QFile>

class FileUtils
{
    public:
        FileUtils();

        static QJsonObject readJson(QString path);
};
