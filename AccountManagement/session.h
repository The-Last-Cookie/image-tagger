#pragma once

#include <QString>

class Session
{
    public:
        Session();
        ~Session();

        bool create(QString username, QString path, bool isLoggedInAsGuest);
        void destroy();

        QString getPath();
        QString getUsername();
        bool isLoggedInAsGuest();

    private:
        bool m_isLoggedIn;
        bool m_isLoggedInAsGuest;
        QString m_username;
        QString m_path;
};

