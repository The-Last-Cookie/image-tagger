#pragma once

#include <QVector>
#include <QString>

#include "querycreationutils.h"
#include "Utils/inputvalidationutils.h"

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
};
