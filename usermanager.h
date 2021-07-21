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
#include "StringCalc/stringcalc.h"

class UserManager
{
    public:
        UserManager();
        ~UserManager();

        void addNewUser(User user);
        void createUserFiles(QString path);
        QString createUserId();
        QString createUserPath();

        bool usernameIsValid(QString username);
};
