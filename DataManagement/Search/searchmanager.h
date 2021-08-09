#pragma once

#include <QObject>
#include <QVariant>
#include <QString>
#include <QVector>
#include <QSqlQuery>

#include "searchresult.h"
#include "searchutils.h"

class SearchManager : public QObject
{
    Q_OBJECT

    public:
        SearchManager();
        ~SearchManager();

        SearchResult retrieveSearchResult(QString searchQuery);

    private:
        QVector<QString> m_args;
        SearchResult m_result;
};
