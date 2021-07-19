#include "logger.h"

Logger::Logger(std::string path) : m_path(path)
{

}

Logger::~Logger()
{

}

void Logger::info(std::string message)
{
    std::string date = getDate("YYYY-MM-DD");

    std::fstream file;
    file.open(m_path + "log_" + date + ".txt", std::ios::out | std::ios::app);

    date = getDate("HH:MM:SS");

    file << date << " INFO: " << message << "\n";
    file.close();
}

void Logger::warning(std::string message)
{
    std::string date = getDate("YYYY-MM-DD");

    std::fstream file;
    file.open(m_path + "log_" + date + ".txt", std::ios::out | std::ios::app);

    date = getDate("HH:MM:SS");

    file << date << " WARNING: " << message << "\n";
    file.close();
}

void Logger::error(std::string message)
{
    std::string date = getDate("YYYY-MM-DD");

    std::fstream file;
    file.open(m_path + "log_" + date + ".txt", std::ios::out | std::ios::app);

    date = getDate("HH:MM:SS");

    file << date << " ERROR: " << message << "\n";
    file.close();
}

std::string Logger::getDate(std::string format)
{
    // original format: 2021-07-19T15:05:29Z
    std::string date = QDateTime::currentDateTime().toTimeSpec(Qt::OffsetFromUTC).toString(Qt::ISODate).toStdString();

    if (format == "YYYY-MM-DD") {
        date = date.substr(0, 10);
    }

    if (format == "HH:MM:SS") {
        date = date.substr(11, 8);
    }

    return date;
}

void Logger::setPath(std::string path)
{
    m_path = path;
}
