#include "accesscontrolsystem.h"

AccessControlSystem *AccessControlSystem::m_instance = nullptr;
AccessControlSystem::AccessControlSystem(QObject *parent) : QObject(parent)
{

}

AccessControlSystem::~AccessControlSystem()
{

}

AccessControlSystem &AccessControlSystem::instance()
{
    // Avoid creating new instances
    if (m_instance == nullptr) {
        m_instance = new AccessControlSystem;
    }

    return *m_instance;
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

    jsonDoc.setObject(jsonObject);
    QByteArray bytes = jsonDoc.toJson(QJsonDocument::Indented);

    file.open(QIODevice::WriteOnly | QIODevice::ExistingOnly | QIODevice::Text);
    QTextStream out(&file);
    out << bytes;
    file.close();

    m_session.destroy();
}

bool AccessControlSystem::login(QString username, QString password)
{
    if (m_um.usernameIsValid(username)) {
        return false;
    }

    QString hash = m_um.retrieveHashFromUser(username);
    if (!m_pwm.comparePasswordWithHash(password, hash)) {
        return false;
    }

    QString path = m_um.retrievePathFromUser(username);
    decryptFiles(path);
    return m_session.create(username, path);
}

void AccessControlSystem::logout()
{
    encryptFiles(m_session.getPath());
    m_session.destroy();
}

bool AccessControlSystem::changePassword(QString oldPassword, QString newPassword, QString newPasswordConfirm)
{
    QString hash = m_um.retrieveHashFromUser(m_session.getUsername());
    if (!m_pwm.comparePasswordWithHash(oldPassword, hash)) {
        return false;
    }

    if (oldPassword == newPassword) {
        return false;
    }

    if (!m_pwm.checkPassword(newPassword)) {
        return false;
    }

    if (newPassword != newPasswordConfirm) {
        return false;
    }

    hash = m_pwm.hashPassword(newPassword);
    return m_um.changePassword(m_session.getPath(), hash);
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

QString AccessControlSystem::getPasswordRulesText()
{
    QString text = "It seems that either that username is already taken or that your password is not safe enough. A password has these constraints: ";
    text.append("**at least %1 characters long**, ");
    text.append("**at least %2 uppercase letters**, ");
    text.append("**at least %3 lowercase letters** and ");
    text.append("**at least one special character** (%4).");

    return text;
}

QString AccessControlSystem::getSessionPath()
{
    return m_session.getPath();
}
