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

        bool createUser(QString name, QString password);
        bool deleteUser();

        bool login();
        bool logout();

        bool changePassword();
        bool validateUser();
        bool usernameIsValid(QString username);

        void encryptFiles(QString path);
        void decryptFiles(QString path);

    private:
        PasswordManager m_pwm;
};
