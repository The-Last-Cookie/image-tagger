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
    dbm.setHostname("SearchManager");
    dbm.openConnection(AccessControlSystem::instance().getSessionPath());

    QSqlQuery query;
    query.prepare(searchQuery);
    for (int i = 0; i < m_args.size(); i++) {
        if (SearchUtils::getKeyword(m_args.at(i)) == "added") {
            // Dates (String)
            query.bindValue(i, QString(SearchUtils::getValue(m_args.at(i))));
        } else if (SearchUtils::getKeyword(m_args.at(i)) == "size") {
            // Size (Integer)
            query.bindValue(i, QString(SearchUtils::getValue(m_args.at(i))).toInt());
        } else {
            // Normal text, used with the LIKE operator
            query.bindValue(i, QString("%%1%").arg(SearchUtils::getValue(m_args.at(i))));
        }
    }
    query.exec();

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
