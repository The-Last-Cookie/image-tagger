#include "passwordmanager.h"

PasswordManager::PasswordManager()
{
    QFile file;
    file.setFileName("data/passwordRules.json");
    if (file.open(QIODevice::WriteOnly | QIODevice::NewOnly | QIODevice::Text)) {
        QJsonObject jsonObject;
        jsonObject.insert("minLength", QJsonValue("8"));
        jsonObject.insert("minNumUpper", QJsonValue("3"));
        jsonObject.insert("minNumUpper", QJsonValue("3"));
        jsonObject.insert("specialChars", QJsonValue("!%$&/\\+#*"));

        QJsonDocument jsonDoc;
        jsonDoc.setObject(jsonObject);

        QByteArray bytes = jsonDoc.toJson(QJsonDocument::Indented);

        QTextStream out(&file);
        out << bytes;

        m_minLength = 8;
        m_minNumUpper = 3;
        m_minNumLower = 3;
        m_specialChars = "!%$&/\\+#*";

        file.close();
        return;
    }

    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString data = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject passwordRules = jsonDoc.object();

    if (passwordRules["minLength"].isNull()) {
        m_minLength = 8;
    } else {
        m_minLength = passwordRules["minLength"].toInt();
    }

    if (passwordRules["minNumUpper"].isNull()) {
        m_minNumUpper = 3;
    } else {
        m_minNumUpper = passwordRules["minNumUpper"].toInt();
    }

    if (passwordRules["minNumLower"].isNull()) {
        m_minNumLower = 3;
    } else {
        m_minNumLower = passwordRules["minNumLower"].toInt();
    }

    if (passwordRules["specialChars"].isNull()) {
        m_specialChars = "!%$&/\\+#*";
    } else {
        m_specialChars = passwordRules["specialChars"].toString();
    }
}

PasswordManager::~PasswordManager()
{

}

bool PasswordManager::checkPassword(QString password)
{
    if (password.length() < m_minLength) {
        return false;
    }

    int numUpper = 0;
    for (int i = 0; i < password.length(); i++) {
        if (password.at(i).isUpper()) {
            numUpper++;
        }

        if (numUpper >= m_minNumUpper) {
            break;
        }
    }
    if (numUpper < m_minNumUpper) {
        return false;
    }

    int numLower = 0;
    for (int i = 0; i < password.length(); i++) {
        if (password.at(i).isLower()) {
            numLower++;
        }

        if (numLower >= m_minNumLower) {
            break;
        }
    }
    if (numLower < m_minNumLower) {
        return false;
    }

    bool containsSpecialChar = false;
    for (int i = 0; i < password.length(); i++) {
        if (m_specialChars.contains(password.at(i))) {
            containsSpecialChar = true;
            break;
        }
    }
    if (!containsSpecialChar) {
        return false;
    }

    return true;
}

QString PasswordManager::hashPassword(QString password)
{
    QByteArray bytes = password.toLocal8Bit();
    if (bytes.length() == 0) {
        return "";
    }

    // Hash with SHA256
    QByteArray hash = QCryptographicHash::hash(bytes, QCryptographicHash::Algorithm(4));
    QString hashString = QString(hash);
    return hashString;
}

bool PasswordManager::comparePasswordWithHash(QString password, QString hash)
{
    if (hash != hashPassword(password)) {
        return false;
    }

    return true;
}

void PasswordManager::setMinLength(int minLength)
{
    if (minLength < 1) {
        return;
    }

    m_minLength = minLength;
}

void PasswordManager::setMinNumUpper(int minNumUpper)
{
    if (minNumUpper < 0) {
        return;
    }

    m_minNumUpper = minNumUpper;
}

void PasswordManager::setMinNumLower(int minNumLower)
{
    if (minNumLower < 0) {
        return;
    }

    m_minNumLower = minNumLower;
}

void PasswordManager::setSpecialChars(QString specialChars)
{
    m_specialChars = specialChars;
}

int PasswordManager::getMinLength()
{
    return m_minLength;
}

int PasswordManager::getMinNumUpper()
{
    return m_minNumUpper;
}

int PasswordManager::getMinNumLower()
{
    return m_minNumLower;
}

QString PasswordManager::getSpecialChars()
{
    return m_specialChars;
}
