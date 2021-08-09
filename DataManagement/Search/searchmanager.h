#pragma once

#include <QObject>
#include <QVariant>
#include <QString>
#include <QVector>
#include <QSqlQuery>

#include "AccountManagement/accesscontrolsystem.h"
#include "searchresult.h"
#include "searchutils.h"
#include "databasemanager.h"

class SearchManager : public QObject
{
    Q_OBJECT

    public:
        explicit SearchManager(QObject *parent = nullptr);
        ~SearchManager();

    public slots:
        void retrieveSearchResult(QString searchQuery);
        SearchResult* getSearchResult();

    private:
        QVector<QString> m_args;
        SearchResult *m_result;
};
