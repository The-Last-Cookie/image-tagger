#include "session.h"

Session::Session()
{
    m_isLoggedIn = false;
}

Session::~Session()
{

}

bool Session::create(QString username, QString path)
{
    if (m_isLoggedIn) {
        return false;
    }

    if (username == "") {
        return false;
    }

    if (path == "") {
        return false;
    }

    m_username = username;
    m_path = path;
    m_isLoggedIn = true;

    return true;
}

void Session::destroy()
{
    m_isLoggedIn = false;
    m_username = "";
    m_path = "";
}

QString Session::getUsername()
{
    return m_username;
}

QString Session::getPath()
{
    return m_path;
}
