#pragma once

#include <QString>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDriver>
#include <QDir>

#include "logger.h"

class DatabaseManager
{
    public:
        DatabaseManager();
        ~DatabaseManager();

        bool openConnection(QString path);

        void setPort(int port);
        void setHostname(QString hostname);
        void setUsername(QString username);

        bool deleteDatabase(QString path);

        bool isOpen();

        void closeConnection();

    private:
        QSqlDatabase m_db;
        bool m_isOpen;
        int m_port;
        QString m_hostname;
        QString m_username;
};

