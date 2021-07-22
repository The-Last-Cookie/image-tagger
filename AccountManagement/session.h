#pragma once

#include <QString>

class Session
{
    public:
        Session();
        ~Session();

        bool create(QString path, bool isLoggedInAsGuest);
        void destroy();

    private:
        bool m_isLoggedIn;
        bool m_isLoggedInAsGuest;
        QString m_path;
};

