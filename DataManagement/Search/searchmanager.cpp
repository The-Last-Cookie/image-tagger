#include "searchmanager.h"

SearchManager::SearchManager(QObject *parent) : QObject(parent)
{

}

SearchManager::~SearchManager()
{

}

void SearchManager::retrieveSearchResult(QString searchQuery)
{
    m_args = SearchUtils::toSingleArgs(searchQuery);

    searchQuery = SearchUtils::convertToSqlQuery(m_args);

    DatabaseManager dbm;
    dbm.openConnection(AccessControlSystem::instance().getSessionPath());

    QSqlQuery query;
    query.exec(searchQuery);

    SearchResult result;
    while (query.next()) {
        BasicFile file;
        file.setId(query.value(0).toInt());
        file.setName(query.value(1).toString());
        file.setExtension(query.value(2).toString());

        result.appendFile(file);
    }

    dbm.closeConnection();
    m_result = &result;
}

SearchResult* SearchManager::getSearchResult()
{
    return m_result;
}
