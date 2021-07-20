#include "databasemanager.h"

DatabaseManager::DatabaseManager()
{

}

DatabaseManager::~DatabaseManager()
{

}

bool DatabaseManager::openConnection(QString path)
{
    if (m_isOpen) {
        return false;
    }

    m_db = m_db.addDatabase("QSQLITE");
    m_db.setHostName(path);
    m_db.setDatabaseName(QCoreApplication::applicationDirPath() + "data/" + path + "/data.sqlite");
    m_db.setUserName("");
    m_db.setPassword("");
    m_isOpen = m_db.open();

    return false;
}

bool DatabaseManager::openConnection(QString path, int port)
{
    if (m_isOpen) {
        return false;
    }

    m_db.setPort(port);

    m_db = m_db.addDatabase("QSQLITE");
    m_db.setHostName(path);
    m_db.setDatabaseName(QCoreApplication::applicationDirPath() + "data/" + path + "/data.sqlite");
    m_db.setUserName("");
    m_db.setPassword("");
    m_isOpen = m_db.open();

    return true;
}

bool DatabaseManager::deleteDatabase(QString path)
{
    return false;
}

bool DatabaseManager::isOpen()
{
    return m_isOpen;
}

bool DatabaseManager::close(QString path)
{
    return false;
}
