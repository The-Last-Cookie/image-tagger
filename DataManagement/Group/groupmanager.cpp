#include "groupmanager.h"

GroupManager::GroupManager(QObject *parent) : QObject(parent)
{

}

GroupManager::~GroupManager()
{

}

bool GroupManager::createGroup(QString name, QString description)
{
    if (!InputValidationUtils::isValidString(name)) {
        return false;
    }

    DatabaseManager dbm;
    dbm.setHostname("GroupManager");
    dbm.openConnection(AccessControlSystem::instance().getSessionPath());

    QSqlQuery query;
    query.prepare("INSERT INTO groups (groupId, name, description) "
                  "VALUES (:groupId, :name, :description)");
    query.bindValue(":groupId", QVariant(QVariant::Int));
    query.bindValue(":name", name);
    query.bindValue(":description", description);
    query.exec();

    if (!query.lastError().text().isEmpty()) {
        return false;
    }

    dbm.closeConnection();
    return true;
}

void GroupManager::addGroupToFile(int groupId, int fileId)
{
    DatabaseManager dbm;
    dbm.setHostname("GroupManager");
    dbm.openConnection(AccessControlSystem::instance().getSessionPath());

    QSqlQuery query;
    query.prepare("INSERT INTO files_groups (fileId, groupId) "
                  "VALUES (:fileId, :groupId)");
    query.bindValue(":fileId", fileId);
    query.bindValue(":groupId", groupId);
    query.exec();

    dbm.closeConnection();
}

bool GroupManager::deleteGroup(int groupId)
{
    DatabaseManager dbm;
    dbm.setHostname("GroupManager");
    dbm.openConnection(AccessControlSystem::instance().getSessionPath());

    QSqlQuery query;
    query.prepare("DELETE FROM groups WHERE groupId = :groupId;");
    query.bindValue(":groupId", groupId);
    query.exec();

    dbm.closeConnection();
    return true;
}
