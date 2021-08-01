#include "filemanager.h"

FileManager::FileManager()
{

}

bool FileManager::addNewFile(QString path, QString oldFilePath)
{
    SettingsManager settings;
    QString importMode = settings.getImportMode(path);

    QFile::copy(oldFilePath, path + "/images");

    if (importMode == "move") {
        QFile oldFile;
        oldFile.setFileName(oldFilePath);
        oldFile.remove();
    }

    QSqlQuery query;
    query.prepare("INSERT INTO files (id, name, fileExtension, added, size) "
                  "VALUES (?, ?, ?, ?, ?)");
    query.bindValue(":id", "");
    query.bindValue(":name", "");
    query.bindValue(":fileExtension", "");
    query.bindValue(":added", "");
    query.bindValue(":size", "");
    query.exec();
}
