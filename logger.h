#pragma once

#include <QTextStream>
#include <QFile>
#include <QDateTime>

class Logger
{
    public:
        Logger(QString path);
        ~Logger();

        void info(QString message);
        void warning(QString message);
        void error(QString message);

        QString getDate(QString format);

        void setPath(QString path);

    private:
        QString m_path;
};
