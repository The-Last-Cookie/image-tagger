#pragma once

#include <QString>

class User
{
    public:
        User();
        ~User();

        void setUsername(QString username);
        void setId(QString id);
        void setPassword(QString password);
        void setPath(QString path);

        QString getUsername();
        QString getId();
        QString getPassword();
        QString getPath();

    private:
        QString m_username;
        QString m_id;
        QString m_password;
        QString m_path;
};

