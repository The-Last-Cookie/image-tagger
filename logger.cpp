#include "logger.h"

#include <QDebug>

Logger::Logger(QString path) : m_path(path)
{

}

Logger::~Logger()
{

}

void Logger::info(QString message)
{
    QString date = getDate("YYYY-MM-DD");

    QFile file;
    file.setFileName(m_path + "/logs/" + "log_" + date + ".txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream out(&file);

        // A log message contains the time in HH:MM:SS
        date = getDate("HH:MM:SS");
        out << date << " INFO: " << message << "\n";
    }

    file.close();
}

void Logger::warning(QString message)
{
    QString date = getDate("YYYY-MM-DD");

    QFile file;
    file.setFileName(m_path + "/logs/" + "log_" + date + ".txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream out(&file);

        // A log message contains the time in HH:MM:SS
        date = getDate("HH:MM:SS");
        out << date << " WARNING: " << message << "\n";
    }

    file.close();
}

void Logger::error(QString message)
{
    QString date = getDate("YYYY-MM-DD");

    QFile file;
    file.setFileName(m_path + "/logs/" + "log_" + date + ".txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream out(&file);

        // A log message contains the time in HH:MM:SS
        date = getDate("HH:MM:SS");
        out << date << " ERROR: " << message << "\n";
    }

    file.close();
}

QString Logger::getDate(QString format)
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

void Logger::setPath(QString path)
{
    m_path = path;
}
