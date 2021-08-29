#pragma once

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QFile>

class FileUtils
{
    Q_OBJECT

    public:
        FileUtils();

        static QJsonObject readJson(QString path);
};

