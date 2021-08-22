#include "dateutils.h"

DateUtils::DateUtils()
{

}

DateUtils::~DateUtils()
{

}

QString DateUtils::getDate(QString format)
{
    // original format: 2021-07-19T15:05:29Z
    QString date = QDateTime::currentDateTime().toTimeSpec(Qt::OffsetFromUTC).toString(Qt::ISODate);

    if (format == "YYYY-MM-DD") {
        date = date.mid(0, 10);
    }

    if (format == "HH:MM:SS") {
        date = date.mid(11, 9);
    }

    return date;
}
