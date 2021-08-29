#pragma once

#include <QString>
#include <QFile>
#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "AccountManagement/user.h"
#include "databasemanager.h"
#include "StringCalc/stringcalc.h"
#include "Utils/fileutils.h"

class UserManager
{
    public:
        UserManager();
        ~UserManager();

        void addNewUser(User user);
        void createUserFiles(QString path);
        QString createUserId();
        QString createUserPath();

        bool changePassword(QString path, QString hash);

        void deleteUserFiles(QString path);

        QString retrieveHashFromUser(QString username);
        QString retrievePathFromUser(QString username);

        bool usernameIsValid(QString username);

    private:
        void createDefaultSettingsFile(QString path);
};
