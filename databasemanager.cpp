#include "databasemanager.h"

DatabaseManager::DatabaseManager()
{
    m_isOpen = false;
    m_port = 0;
}

DatabaseManager::~DatabaseManager()
{

}

bool DatabaseManager::openConnection(QString path)
{
    if (m_isOpen) {
        return false;
    }

    m_db = QSqlDatabase::addDatabase("QSQLITE");

    if (m_port != 0) {
        m_db.setPort(m_port);
    }

    if (m_hostname != "") {
        m_db.setHostName(m_hostname);
    }

    if (m_username != "") {
        m_db.setUserName(m_username);
    }

    m_db.setDatabaseName("data/" + path + "/data.sqlite");
    m_isOpen = m_db.open();

    return m_isOpen;
}

void DatabaseManager::setPort(int port)
{
    if (port < 1) {
        return;
    }

    m_port = port;
}

void DatabaseManager::setHostname(QString hostname)
{
    m_hostname = hostname;
}

void DatabaseManager::setUsername(QString username)
{
    m_username = username;
}

bool DatabaseManager::deleteDatabase(QString path)
{
    return QFile::remove(QDir::currentPath() + "/data/" + path + "/data.sqlite");
}

bool DatabaseManager::isOpen()
{
    return m_isOpen;
}

void DatabaseManager::closeConnection()
{
    m_isOpen = false;
    m_db.close();
}
