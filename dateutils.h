#pragma once

#include <QString>
#include <QDateTime>

class DateUtils
{
    public:
        DateUtils();
        ~DateUtils();

        QString getDate(QString format);
};

