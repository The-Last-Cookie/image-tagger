#include "tagmanager.h"

TagManager::TagManager(QObject *parent) : QObject(parent)
{

}

TagManager::~TagManager()
{

}

bool TagManager::createTag(QString name, QString description)
{
    if (name == "") {
        return false;
    }

    DatabaseManager dbm;
    dbm.setHostname("TagManager");
    dbm.openConnection(AccessControlSystem::instance().getSessionPath());

    QSqlQuery query;
    query.prepare("INSERT INTO tags (tagId, name, description) "
                  "VALUES (:tagId, :name, :description)");
    query.bindValue(":tagId", QVariant(QVariant::Int));
    query.bindValue(":name", name);
    query.bindValue(":description", description);
    query.exec();

    dbm.closeConnection();
    return true;
}

void TagManager::addTagToFile(int tagId, int fileId)
{
    DatabaseManager dbm;
    dbm.setHostname("TagManager");
    dbm.openConnection(AccessControlSystem::instance().getSessionPath());

    QSqlQuery query;
    query.prepare("INSERT INTO files_tags (fileId, tagId) "
                  "VALUES (:fileId, :tagId)");
    query.bindValue(":fileId", fileId);
    query.bindValue(":tagId", tagId);
    query.exec();

    dbm.closeConnection();
}

bool TagManager::deleteTag(int tagId)
{
    DatabaseManager dbm;
    dbm.setHostname("TagManager");
    dbm.openConnection(AccessControlSystem::instance().getSessionPath());

    QSqlQuery query;
    query.prepare("DELETE FROM tags WHERE tagId = :tagId;");
    query.bindValue(":tagId", tagId);
    query.exec();

    dbm.closeConnection();
    return true;
}
