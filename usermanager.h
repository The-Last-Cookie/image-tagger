#pragma once

#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "user.h"

class UserManager
{
    public:
        UserManager();
        ~UserManager();

        void addNewUser(User user);
        void createUserFiles(QString path);
};

