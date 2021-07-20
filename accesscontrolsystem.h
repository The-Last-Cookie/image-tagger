#pragma once

#include <QObject>
#include <QFile>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QTextStream>

#include "passwordmanager.h"

class AccessControlSystem : public QObject
{
    Q_OBJECT

    public:
        AccessControlSystem();
        ~AccessControlSystem();

        bool createUser(std::string name, std::string password);
        bool deleteUser();

        bool login();
        bool logout();

        bool changePassword();
        bool validateUser();
        bool usernameIsValid(std::string username);

        void encryptFiles(std::string path);
        void decryptFiles(std::string path);

    private:
        PasswordManager m_pwm;
};
