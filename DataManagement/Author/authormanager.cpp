#include "authormanager.h"

AuthorManager::AuthorManager(QObject *parent) : QObject(parent)
{

}

AuthorManager::~AuthorManager()
{

}

bool AuthorManager::createAuthor(QString name, QString description)
{
    if (name.isEmpty() || name.contains(" ")) {
            return false;
    }

    DatabaseManager dbm;
    dbm.setHostname("AuthorManager");
    dbm.openConnection(AccessControlSystem::instance().getSessionPath());

    QSqlQuery query;
    query.prepare("INSERT INTO authors (authorId, name, description) "
                  "VALUES (:authorId, :name, :description)");
    query.bindValue(":authorId", QVariant(QVariant::Int));
    query.bindValue(":name", name);
    query.bindValue(":description", description);
    query.exec();

    if (!query.lastError().text().isEmpty()) {
        return false;
    }

    dbm.closeConnection();
    return true;
}

void AuthorManager::addAuthorToFile(int authorId, int fileId)
{
    DatabaseManager dbm;
    dbm.setHostname("AuthorManager");
    dbm.openConnection(AccessControlSystem::instance().getSessionPath());

    QSqlQuery query;
    query.prepare("INSERT INTO files_authors (fileId, authorId) "
                  "VALUES (:fileId, :authorId)");
    query.bindValue(":fileId", fileId);
    query.bindValue(":authorId", authorId);
    query.exec();

    dbm.closeConnection();
}

bool AuthorManager::deleteAuthor(int authorId)
{
    DatabaseManager dbm;
    dbm.setHostname("AuthorManager");
    dbm.openConnection(AccessControlSystem::instance().getSessionPath());

    QSqlQuery query;
    query.prepare("DELETE FROM authors WHERE authorId = :authorId;");
    query.bindValue(":authorId", authorId);
    query.exec();

    dbm.closeConnection();
    return true;
}
