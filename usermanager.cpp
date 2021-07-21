#include "usermanager.h"

UserManager::UserManager()
{

}

UserManager::~UserManager()
{

}

void UserManager::addNewUser(User user)
{
    QFile file;
    file.setFileName("data/users.json");
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    QString data = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();

    QJsonObject newUser;
    newUser.insert("name", QJsonValue(user.getName()));
    newUser.insert("id", QJsonValue(user.getId()));
    newUser.insert("password", QJsonValue(user.getPassword()));
    newUser.insert("path", QJsonValue(user.getPath()));

    QJsonArray users = jsonObject["users"].toArray();
    users.append(newUser);

    jsonObject["users"] = users;

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        jsonDoc.setObject(jsonObject);

        QByteArray bytes = jsonDoc.toJson(QJsonDocument::Indented);

        QTextStream out(&file);
        out << bytes;
    }

    file.close();
}

void UserManager::createUserFiles(QString path)
{
    // Create folder "images" for saving images
    QDir dir("data/" + path);
    dir.mkpath("images");

    // Create database
    DatabaseManager dbm;
    dbm.openConnection(path);

    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON;");

    query.exec(
        "CREATE TABLE files"
        "("
        "fileId INTEGER NOT NULL UNIQUE,"
        "name TEXT,"
        "fileExtension TEXT,"
        "added DATE,"
        "size INTEGER,"
        "PRIMARY KEY (fileId)"
        ")"
    );

    query.exec(
        "CREATE TABLE authors"
        "("
        "authorId INTEGER NOT NULL UNIQUE,"
        "name TEXT,"
        "description TEXT,"
        "PRIMARY KEY (authorId)"
        ")"
    );

    query.exec(
        "CREATE TABLE tags"
        "("
        "tagId INTEGER NOT NULL UNIQUE,"
        "name TEXT,"
        "description TEXT,"
        "PRIMARY KEY (tagId)"
        ")"
    );

    query.exec(
        "CREATE TABLE groups"
        "("
        "groupId INTEGER NOT NULL UNIQUE,"
        "name TEXT,"
        "description TEXT,"
        "PRIMARY KEY (groupId)"
        ")"
    );

    query.exec(
        "CREATE TABLE files_tags"
        "("
        "fileId INTEGER,"
        "tagId INTEGER,"
        "FOREIGN KEY (fileId) REFERENCES files (fileId) ON DELETE CASCADE,"
        "FOREIGN KEY (tagId) REFERENCES tags (tagId) ON DELETE CASCADE,"
        "PRIMARY KEY (fileId, tagId)"
        ")"
    );

    query.exec(
        "CREATE TABLE files_authors"
        "("
        "fileId INTEGER,"
        "authorId INTEGER,"
        "FOREIGN KEY (fileId) REFERENCES files (fileId) ON DELETE CASCADE,"
        "FOREIGN KEY (authorId) REFERENCES author (authorId) ON DELETE CASCADE,"
        "PRIMARY KEY (fileId, authorId)"
        ")"
    );

    query.exec(
        "CREATE TABLE files_groups"
        "("
        "fileId INTEGER,"
        "groupId INTEGER,"
        "FOREIGN KEY (fileId) REFERENCES files (fileId) ON DELETE CASCADE,"
        "FOREIGN KEY (groupId) REFERENCES groups (groupId) ON DELETE CASCADE,"
        "PRIMARY KEY (fileId, groupId)"
        ")"
    );

    query.exec(
        "CREATE TABLE associations"
        "("
        "parentId INTEGER,"
        "childId INTEGER CHECK (childId != parentId),"
        "FOREIGN KEY (parentId) REFERENCES files (fileId) ON DELETE CASCADE,"
        "FOREIGN KEY (childId) REFERENCES files (fileId) ON DELETE CASCADE,"
        "PRIMARY KEY (parentId, childId)"
        ")"
    );

    query.exec(
        "CREATE TABLE favorites"
        "("
        "fileId INTEGER NOT NULL UNIQUE,"
        "PRIMARY KEY (fileId)"
        ")"
    );

    dbm.closeConnection();

    // Create settings.json
    SettingsManager settingsManager;
    QJsonObject settings = settingsManager.createDefaultSettingsFile();

    QJsonDocument jsonDoc;
    QFile file;
    file.setFileName("data/" + path);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        jsonDoc.setObject(settings);

        QByteArray bytes = jsonDoc.toJson(QJsonDocument::Indented);

        QTextStream out(&file);
        out << bytes;
    }
    file.close();

    // Create folder "logs" for saving logs
    dir.mkpath("logs");
}

QString UserManager::createUserId()
{
    QFile file;
    file.setFileName("data/users.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString data = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();

    QJsonArray users = jsonObject["users"].toArray();

    QJsonValue lastUser = users.last();
    QString id = lastUser["id"].toString();

    QString newId = QString::fromStdString(StringCalc::Decimal::add(id.toStdString(), "1"));

    return newId;
}
