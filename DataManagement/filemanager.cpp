#include "filemanager.h"

FileManager::FileManager()
{

}

bool FileManager::addNewFile(QString path, QString oldFilePath)
{
    SettingsManager settings;
    QString importMode = settings.getImportMode(path);

    QFile oldFile;
    oldFile.setFileName(oldFilePath);

    QString name = QStringRef(&oldFilePath,
                              oldFilePath.lastIndexOf("/"),
                              oldFilePath.lastIndexOf(".") - oldFilePath.lastIndexOf("/")).toString();
    QString fileExtension = QStringRef(&oldFilePath, oldFilePath.lastIndexOf("."), oldFilePath.length()).toString();
    QString added = "01-01-0000";
    QString size = "1";

    oldFile.copy(oldFilePath, QDir::currentPath() + path + "/images");

    if (importMode == "move") {
        oldFile.remove();
    }

    QSqlQuery query;
    query.prepare("INSERT INTO files (id, name, fileExtension, added, size) "
                  "VALUES (?, ?, ?, ?)");
    query.bindValue(":name", name);
    query.bindValue(":fileExtension", fileExtension);
    query.bindValue(":added", added);
    query.bindValue(":size", size);
    query.exec();
}

bool FileManager::deleteFile(QString path)
{

}
