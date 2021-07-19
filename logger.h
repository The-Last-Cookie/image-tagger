#pragma once

#include <iostream>
#include <fstream>
#include <QDateTime>

class Logger
{
    public:
        Logger(std::string path);
        ~Logger();

        void info(std::string message);
        void warning(std::string message);
        void error(std::string message);

        std::string getDate(std::string format);

        void setPath(std::string path);

    private:
        std::string m_path;
};
