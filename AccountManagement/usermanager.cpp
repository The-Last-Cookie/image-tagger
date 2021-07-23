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
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString data = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();

    QJsonObject newUser;
    newUser.insert("username", QJsonValue(user.getName()));
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
        "PRIMARY KEY (fileId ASC)"
        ")"
    );

    query.exec(
        "CREATE TABLE authors"
        "("
        "authorId INTEGER NOT NULL UNIQUE,"
        "name TEXT,"
        "description TEXT,"
        "PRIMARY KEY (authorId ASC)"
        ")"
    );

    query.exec(
        "CREATE TABLE tags"
        "("
        "tagId INTEGER NOT NULL UNIQUE,"
        "name TEXT,"
        "description TEXT,"
        "PRIMARY KEY (tagId  ASC)"
        ")"
    );

    query.exec(
        "CREATE TABLE groups"
        "("
        "groupId INTEGER NOT NULL UNIQUE,"
        "name TEXT,"
        "description TEXT,"
        "PRIMARY KEY (groupId  ASC)"
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
        "PRIMARY KEY (fileId ASC)"
        ")"
    );

    dbm.closeConnection();

    // Create settings.json
    SettingsManager settingsManager;
    QJsonObject settings = settingsManager.createDefaultSettingsFile();

    QFile file;
    file.setFileName("data/" + path + "/settings.json");
    if (file.open(QIODevice::WriteOnly | QIODevice::NewOnly | QIODevice::Text)) {
        QJsonDocument jsonDoc;
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

    if (users.isEmpty()) {
        return "1";
    }

    QJsonValue lastUser = users.last();
    QString id = lastUser["id"].toString();

    QString newId = QString::fromStdString(StringCalc::Decimal::add(id.toStdString(), "1"));

    return newId;
}

QString UserManager::createUserPath()
{
    //QDir dir = QCoreApplication::applicationDirPath();
    QDir dir("data/");
    QFileInfoList fileList = dir.entryInfoList(QDir::Filters(QDir::Dirs | QDir::NoDotAndDotDot), QDir::SortFlags(QDir::Name));

    if (fileList.isEmpty()) {
        return "1";
    }

    QString lastFileName = fileList.last().fileName();
    QString newFileName = QString::fromStdString(StringCalc::Decimal::add(lastFileName.toStdString(),"1"));

    return newFileName;
}

void UserManager::deleteUserFiles(QString path)
{
    QFile::remove("data/" + path);
}

bool UserManager::usernameIsValid(QString username)
{
    if (username.isEmpty()) {
        return false;
    }

    // Read in data
    QFile file;
    file.setFileName("data/users.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString data = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();

    QJsonArray users = jsonObject["users"].toArray();

    if (users.isEmpty()) {
        return true;
    }

    bool usernameExists = false;
    for (int i = 0; i < users.size(); i++) {
        if (users.at(i)["username"] == username) {
            usernameExists = true;
            break;
        }
    }
    if (usernameExists) {
        return false;
    }

    return true;
}

QString UserManager::retrieveHashFromUser(QString username)
{
    if (username.isEmpty()) {
        return "";
    }

    QFile file;
    file.setFileName("data/users.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString data = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();

    QJsonArray users = jsonObject["users"].toArray();

    if (users.isEmpty()) {
        return "";
    }

    for (int i = 0; i < users.size(); i++) {
        if (users.at(i)["username"] == username) {
            return users.at(i)["password"].toString();
        }
    }

    return "";
}

QString UserManager::retrievePathFromUser(QString username)
{
    if (username.isEmpty()) {
        return "";
    }

    QFile file;
    file.setFileName("data/users.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString data = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();

    QJsonArray users = jsonObject["users"].toArray();

    if (users.isEmpty()) {
        return "";
    }

    for (int i = 0; i < users.size(); i++) {
        if (users.at(i)["username"] == username) {
            return users.at(i)["path"].toString();
        }
    }

    return "";
}
