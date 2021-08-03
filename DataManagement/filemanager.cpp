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
    QString fileExtension = QStringRef(&oldFilePath,
                                       positionOfLastPoint + 1,
                                       oldFilePath.length() - positionOfLastPoint - 1).toString();
    QString added = DateUtils::getDate("YYYY-MM-DD");
    QString size = QString::number(oldFile.size());

    QString newFilePath = QDir::currentPath() + "/data/" + path + "/images/" + name + "." + fileExtension;
    if (!oldFile.copy(oldFilePath, newFilePath)) {
        return false;
    }

    if (importMode == "move") {
        oldFile.remove();
    }

    DatabaseManager dbm;
    dbm.openConnection(path);

    // TODO: check database query
    QSqlQuery query;
    query.prepare("INSERT INTO files (fileId, name, fileExtension, added, size) "
                  "VALUES (?, ?, ?, ?, ?)");
    query.bindValue(0, "null");
    query.bindValue(1, name);
    query.bindValue(2, fileExtension);
    query.bindValue(3, added);
    query.bindValue(4, size);
    query.exec();

    dbm.closeConnection();

    return true;
}

bool FileManager::deleteFile(QString path, QString filename)
{
    return false;
}
