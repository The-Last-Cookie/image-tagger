#pragma once

#include <QString>

class Session
{
    public:
        Session();
        ~Session();

        bool create(QString path, bool isLoggedInAsGuest);
        void destroy();

        QString getPath();
        bool isLoggedInAsGuest();

    private:
        bool m_isLoggedIn;
        bool m_isLoggedInAsGuest;
        QString m_path;
};

