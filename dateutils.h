#pragma once

#include <QString>
#include <QDateTime>

class DateUtils
{
    public:
        DateUtils();
        ~DateUtils();

        static QString getDate(QString format);
};

