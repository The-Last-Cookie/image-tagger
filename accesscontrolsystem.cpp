#include "accesscontrolsystem.h"

AccessControlSystem::AccessControlSystem()
{
    // If not available, create users.json
    QFile file;
    file.setFileName("data/users.json");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QJsonObject jsonObject;
        jsonObject.insert("users", QJsonArray());

        QJsonDocument jsonDoc;
        jsonDoc.setObject(jsonObject);

        QByteArray bytes = jsonDoc.toJson(QJsonDocument::Indented);

        QTextStream out(&file);
        out << bytes;
    }

    file.close();
}

AccessControlSystem::~AccessControlSystem()
{

}

bool AccessControlSystem::createUser(QString name, QString password)
{
    if (!usernameIsValid(name)) {
        return false;
    }

    if(!m_pwm.checkPassword(password)) {
        return false;
    }

    // Add new user to user file
    User user;
    UserManager um;
    user.setName(name);
    user.setId(um.createUserId());
    user.setPassword(password);
    user.setPath(um.createUserPath());
    um.addNewUser(user);

    // Create new files in user path
    um.createUserFiles(user.getPath());

    return true;
}

bool AccessControlSystem::usernameIsValid(QString username)
{
    // Read in data
    QFile file;
    file.setFileName("data/users.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString data = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();

    QStringList keys = jsonObject.keys();

    if (keys.contains(username)) {
        return false;
    }

    return true;
}
