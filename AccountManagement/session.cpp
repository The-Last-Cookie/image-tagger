#include "session.h"

Session::Session()
{
    m_isLoggedIn = false;
    m_isLoggedInAsGuest = false;
}

Session::~Session()
{

}

bool Session::create(QString path, bool isLoggedInAsGuest)
{
    if (m_isLoggedIn) {
        return false;
    }

    if (path == "") {
        return false;
    }

    if (isLoggedInAsGuest) {
        m_isLoggedInAsGuest = true;
    }

    m_path = path;
    m_isLoggedIn = true;

    return true;
}

void Session::destroy()
{
    m_isLoggedIn = false;
    m_isLoggedInAsGuest = false;
    m_path = "";
}

QString Session::getPath()
{
    return m_path;
}

bool Session::isLoggedInAsGuest()
{
    return m_isLoggedInAsGuest;
}
