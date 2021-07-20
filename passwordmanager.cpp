#include "passwordmanager.h"

PasswordManager::PasswordManager()
{

}

PasswordManager::~PasswordManager()
{

}

bool PasswordManager::checkPassword(std::string password)
{
    return false;
}

std::string PasswordManager::hashPassword(std::string password)
{
    return "";
}

bool PasswordManager::comparePasswordWithHash(std::string password, std::string hash)
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

void PasswordManager::setSpecialChars(std::string specialChars)
{
    m_specialChars = specialChars;
}
