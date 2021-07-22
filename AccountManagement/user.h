#pragma once

#include <QString>

class User
{
    public:
        User();
        ~User();

        void setName(QString name);
        void setId(QString id);
        void setPassword(QString password);
        void setPath(QString path);

        QString getName();
        QString getId();
        QString getPassword();
        QString getPath();

    private:
        QString m_name;
        QString m_id;
        QString m_password;
        QString m_path;
};

