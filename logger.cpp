#include "logger.h"

Logger::Logger(QString path) : m_path(path)
{

}

Logger::~Logger()
{

}

void Logger::info(QString message)
{
    QString date = DateUtils::getDate("YYYY-MM-DD");

    QFile file;
    file.setFileName(m_path + "/logs/" + "log_" + date + ".txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream out(&file);

        // A log message contains the time in HH:MM:SS
        date = DateUtils::getDate("HH:MM:SS");
        out << date << " INFO: " << message << "\n";
    }

    file.close();
}

void Logger::warning(QString message)
{
    QString date = DateUtils::getDate("YYYY-MM-DD");

    QFile file;
    file.setFileName(m_path + "/logs/" + "log_" + date + ".txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream out(&file);

        // A log message contains the time in HH:MM:SS
        date = DateUtils::getDate("HH:MM:SS");
        out << date << " WARNING: " << message << "\n";
    }

    file.close();
}

void Logger::error(QString message)
{
    QString date = DateUtils::getDate("YYYY-MM-DD");

    QFile file;
    file.setFileName(m_path + "/logs/" + "log_" + date + ".txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream out(&file);

        // A log message contains the time in HH:MM:SS
        date = DateUtils::getDate("HH:MM:SS");
        out << date << " ERROR: " << message << "\n";
    }

    file.close();
}

void Logger::setPath(QString path)
{
    m_path = path;
}
