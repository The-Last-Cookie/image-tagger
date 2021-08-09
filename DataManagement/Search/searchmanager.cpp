#include "searchmanager.h"

SearchManager::SearchManager()
{

}

SearchResult SearchManager::retrieveSearchResult(QString searchQuery)
{
    m_args = SearchUtils::toSingleArgs(searchQuery);

    searchQuery = SearchUtils::convertToSqlQuery(m_args);

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

    return result;
}
