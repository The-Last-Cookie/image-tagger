#pragma once

#include <QString>
#include <QFile>
#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "user.h"
#include "databasemanager.h"
#include "settingsmanager.h"

class UserManager
{
    public:
        UserManager();
        ~UserManager();

        void addNewUser(User user);
        void createUserFiles(QString path);
};

