#include "user.h"

User::User()
{

}

User::~User()
{

}

void User::setUsername(QString username)
{
    m_username = username;
}

void User::setId(QString id)
{
    m_id = id;
}

void User::setPassword(QString password)
{
    m_password = password;
}

void User::setPath(QString path)
{
    m_path = path;
}

QString User::getUsername()
{
    return m_username;
}

QString User::getId()
{
    return m_id;
}

QString User::getPassword()
{
    return m_password;
}

QString User::getPath()
{
    return m_path;
}
