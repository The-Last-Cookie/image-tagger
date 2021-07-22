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

bool AccessControlSystem::createUser(QString name, QString password)
{
    if (!m_um.usernameIsValid(name)) {
        return false;
    }

    if(!m_pwm.checkPassword(password)) {
        return false;
    }

    // Add new user to user file
    User user;
    user.setName(name);
    user.setId(m_um.createUserId());
    user.setPassword(m_pwm.hashPassword(password));
    user.setPath(m_um.createUserPath());
    m_um.addNewUser(user);

    // Create new files in user path
    m_um.createUserFiles(user.getPath());

    return true;
}

bool AccessControlSystem::deleteUser()
{
    return false;
}

bool AccessControlSystem::login()
{
    return false;
}
bool AccessControlSystem::logout()
{
    return false;
}

bool AccessControlSystem::changePassword()
{
    return false;
}
bool AccessControlSystem::validateUser()
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

