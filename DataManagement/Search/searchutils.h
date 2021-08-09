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

        static bool hasKeyword(QString string);
        static QString getKeyword(QString string);
        static QString getValue(QString string);
        static QString sanitizeArg(QString string);
};
