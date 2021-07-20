#pragma once

#include <QString>
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
        bool openConnection(QString path, int port);

        bool deleteDatabase(QString path);

        bool isOpen();

        bool close(QString path);

    private:
        QSqlDatabase m_db;
        bool m_isOpen;
};

