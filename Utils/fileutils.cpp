#include "fileutils.h"

FileUtils::FileUtils()
{

}

QJsonObject FileUtils::readJson(QString path)
{
    QFile file;
    file.setFileName(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString data = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();

    return jsonObject;
}
