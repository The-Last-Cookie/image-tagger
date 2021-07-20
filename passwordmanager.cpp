#include "passwordmanager.h"

PasswordManager::PasswordManager()
{

}

PasswordManager::~PasswordManager()
{

}

bool PasswordManager::checkPassword(QString password)
{
    return false;
}

QString PasswordManager::hashPassword(QString password)
{
    return "";
}

bool PasswordManager::comparePasswordWithHash(QString password, QString hash)
{
    return false;
}

void PasswordManager::setMinLength(int minLength)
{
    m_minLength = minLength;
}

void PasswordManager::setMinNumUpper(int minNumUpper)
{
    m_minNumUpper = minNumUpper;
}

void PasswordManager::setMinNumLower(int minNumLower)
{
    m_minNumLower = minNumLower;
}

void PasswordManager::setSpecialChars(QString specialChars)
{
    m_specialChars = specialChars;
}
