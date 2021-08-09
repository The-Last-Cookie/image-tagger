#pragma once

#include <QVector>
#include <QString>

class SearchUtils
{
    public:
        SearchUtils();
        ~SearchUtils();

        static QVector<QString> toSingleArgs(QString query);
        static QString convertToSqlQuery(QVector<QString> args);
};
