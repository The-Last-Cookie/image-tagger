#include "filemanager.h"

FileManager::FileManager()
{

}

FileManager::~FileManager()
{

}

bool FileManager::addNewFile(QString path, QString oldFilePath)
{
    SettingsManager settings;
    QString importMode = settings.getImportMode(path);

    QFile oldFile;
    QUrl url = oldFilePath;
    oldFilePath = url.toLocalFile();
    oldFile.setFileName(oldFilePath);

    int positionOfLastSlash = oldFilePath.lastIndexOf("/");
    int positionOfLastPoint = oldFilePath.lastIndexOf(".");

    QString name = QStringRef(&oldFilePath,
                              positionOfLastSlash + 1,
                              positionOfLastPoint - positionOfLastSlash - 1).toString();
    QString extension = QStringRef(&oldFilePath,
                                   positionOfLastPoint + 1,
                                   oldFilePath.length() - positionOfLastPoint - 1).toString();
    QString added = DateUtils::getDate("YYYY-MM-DD");
    QString size = QString::number(oldFile.size());

    QString newFilePath = QDir::currentPath() + "/data/" + path + "/images/" + name + "." + extension;
    if (!oldFile.copy(oldFilePath, newFilePath)) {
        return false;
    }

    if (importMode == "move") {
        oldFile.remove();
    }

    DatabaseManager dbm;
    dbm.openConnection(path);

    QSqlQuery query;
    query.prepare("INSERT INTO files (fileId, name, extension, added, size) "
                  "VALUES (:fileId, :name, :extension, :added, :size)");
    query.bindValue(":fileId", QVariant(QVariant::Int));
    query.bindValue(":name", name);
    query.bindValue(":extension", extension);
    query.bindValue(":added", added);
    query.bindValue(":size", size);
    query.exec();

    dbm.closeConnection();

    return true;
}

bool FileManager::deleteFile(QString path, int fileId, QString name, QString extension)
{
    QFile file;
    file.setFileName(QDir::currentPath() + "/data/" + path + "/" + name + "." + extension);
    if (!file.remove()) {
        return false;
    }

    DatabaseManager dbm;
    dbm.openConnection(path);

    QSqlQuery query;
    query.prepare("DELETE FROM files WHERE fileId = :fileId;");
    query.bindValue(":fileId", fileId);
    query.exec();

    dbm.closeConnection();
    return true;
}
