#pragma once

#include <QString>
#include <QFile>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QCoreApplication>

#include "logger.h"

class DatabaseManager
{
    public:
        DatabaseManager();
        ~DatabaseManager();

        bool openConnection(QString path);

        void setPort(int port);

        bool deleteDatabase(QString path);

        bool isOpen();

        void closeConnection();

    private:
        QSqlDatabase m_db;
        bool m_isOpen;
        int m_port;
};

