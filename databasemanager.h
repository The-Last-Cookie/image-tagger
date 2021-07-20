#pragma once

#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

class DatabaseManager
{
    public:
        DatabaseManager();
        ~DatabaseManager();

        void addDatabase(QString path);
        void addDatabase(QString path, int port);

        bool deleteDatabase(QString path);

        bool isOpen();

        bool close(QString path);

    private:
        QSqlDatabase m_database;
        bool m_isOpen;
};

