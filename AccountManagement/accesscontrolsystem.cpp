#include "accesscontrolsystem.h"

AccessControlSystem::AccessControlSystem()
{
    Logger l("");

    // If not available, create users.json
    QFile file;
    file.setFileName("data/users.json");
    if (file.open(QIODevice::WriteOnly | QIODevice::NewOnly | QIODevice::Text)) {
        QJsonObject jsonObject;
        jsonObject.insert("users", QJsonArray());

        QJsonDocument jsonDoc;
        jsonDoc.setObject(jsonObject);

        QByteArray bytes = jsonDoc.toJson(QJsonDocument::Indented);

        QTextStream out(&file);
        out << bytes;

        l.info("Created file users.json");
    }
    file.close();
}

AccessControlSystem::~AccessControlSystem()
{

}

bool AccessControlSystem::createUser(QString username, QString password)
{
    if (!m_um.usernameIsValid(username)) {
        return false;
    }

    if(!m_pwm.checkPassword(password)) {
        return false;
    }

    // Add new user to user file
    User user;
    user.setUsername(username);
    user.setId(m_um.createUserId());
    user.setPassword(m_pwm.hashPassword(password));
    user.setPath(m_um.createUserPath());
    m_um.addNewUser(user);

    // Create new files in user path
    m_um.createUserFiles(user.getPath());

    return true;
}

void AccessControlSystem::deleteUser()
{
    m_um.deleteUserFiles(m_session.getPath());

    // Delete user from users.json
    QFile file;
    file.setFileName("data/users.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString data = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();

    QJsonArray users = jsonObject["users"].toArray();

    if (users.isEmpty()) {
        return;
    }

    for (int i = 0; i < users.size(); i++) {
        if (users.at(i)["path"] == m_session.getPath()) {
            users.removeAt(i);
            break;
        }
    }

    jsonObject.insert("users", QJsonValue(users));

    QByteArray bytes = jsonDoc.toJson(QJsonDocument::Indented);

    file.open(QIODevice::WriteOnly | QIODevice::ExistingOnly | QIODevice::Text);
    QTextStream out(&file);
    out << bytes;
    file.close();

    m_session.destroy();
}

bool AccessControlSystem::login(QString username, QString password, bool isLoggedInAsGuest)
{
    if (isLoggedInAsGuest) {
        QString path = m_um.createUserPath();
        m_um.createUserFiles(path);

        return m_session.create(path, isLoggedInAsGuest);
    }

    if (m_um.usernameIsValid(username)) {
        return false;
    }

    QString hash = m_um.retrieveHashFromUser(username);
    if (!m_pwm.comparePasswordWithHash(password, hash)) {
        return false;
    }

    QString path = m_um.retrievePathFromUser(username);
    return m_session.create(path, isLoggedInAsGuest);
}

void AccessControlSystem::logout()
{
    if (m_session.isLoggedInAsGuest()) {
        m_um.deleteUserFiles(m_session.getPath());
    }

    m_session.destroy();
}

bool AccessControlSystem::changePassword()
{
    return false;
}

void AccessControlSystem::encryptFiles(QString path)
{

}

void AccessControlSystem::decryptFiles(QString path)
{

}

int AccessControlSystem::getPasswordMinLength()
{
    return m_pwm.getMinLength();
}

int AccessControlSystem::getPasswordMinNumUpper()
{
    return m_pwm.getMinNumUpper();
}

int AccessControlSystem::getPasswordMinNumLower()
{
    return m_pwm.getMinNumLower();
}

QString AccessControlSystem::getPasswordSpecialChars()
{
    return m_pwm.getSpecialChars();
}
