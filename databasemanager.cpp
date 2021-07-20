#include "databasemanager.h"

DatabaseManager::DatabaseManager()
{
    m_port = -1;
}

DatabaseManager::~DatabaseManager()
{

}

bool DatabaseManager::openConnection(QString path)
{
    if (m_isOpen) {
        return false;
    }

    if (m_port != -1) {
        m_db.setPort(m_port);
    }

    m_db = m_db.addDatabase("QSQLITE");
    m_db.setHostName("");
    m_db.setDatabaseName(QCoreApplication::applicationDirPath() + "data/" + path + "/data.sqlite");
    m_db.setUserName("");
    m_db.setPassword("");
    m_isOpen = m_db.open();

    return m_isOpen;
}

void DatabaseManager::setPort(int port)
{
    if (!m_isOpen) {
        return;
    }

    m_port = port;
}

bool DatabaseManager::deleteDatabase(QString path)
{
    return QFile::remove(QCoreApplication::applicationDirPath() + "data/" + path + "/data.sqlite");
}

bool DatabaseManager::isOpen()
{
    return m_isOpen;
}

void DatabaseManager::closeConnection()
{
    m_db.close();
}
