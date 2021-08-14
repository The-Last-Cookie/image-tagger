#pragma once

#include <QObject>

#include "AccountManagement/accesscontrolsystem.h"
#include "databasemanager.h"

class AuthorManager : public QObject
{
    Q_OBJECT

    public:
        explicit AuthorManager(QObject *parent = nullptr);
        ~AuthorManager();

    public slots:
        bool createAuthor(QString name, QString description);
        void addAuthorToFile(int authorId, int fileId);
        bool deleteAuthor(int authorId);
};
