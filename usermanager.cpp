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
    dbm.addDatabase(path);

    // Create settings.json
    QJsonObject jsonObject;
    jsonObject.insert("theme", "white");

    QJsonDocument jsonDoc;
    QFile file;
    file.setFileName("data/" + path);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        jsonDoc.setObject(jsonObject);

        QByteArray bytes = jsonDoc.toJson(QJsonDocument::Indented);

        QTextStream out(&file);
        out << bytes;
    }
    file.close();

    // Create folder "logs" for saving logs
    dir.mkpath("logs");
}
