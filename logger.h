#pragma once

#include <QTextStream>
#include <QDir>
#include <QFile>

#include "Utils/dateutils.h"

class Logger
{
    public:
        Logger();
        Logger(QString path);
        ~Logger();

        void info(QString message);
        void warning(QString message);
        void error(QString message);

        void setPath(QString path);

    private:
        QString m_path;
};
