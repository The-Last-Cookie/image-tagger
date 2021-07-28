#pragma once

#include <QString>

class Session
{
    public:
        Session();
        ~Session();

        bool create(QString username, QString path);
        void destroy();

        QString getPath();
        QString getUsername();

    private:
        bool m_isLoggedIn;
        QString m_username;
        QString m_path;
};

