#pragma once

#include <QObject>
#include <QFile>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QTextStream>

#include "logger.h"
#include "AccountManagement/passwordmanager.h"
#include "AccountManagement/usermanager.h"

class AccessControlSystem : public QObject
{
    Q_OBJECT

    public:
        AccessControlSystem();
        ~AccessControlSystem();

    public slots:
        bool createUser(QString name, QString password);
        bool deleteUser();

        bool login();
        bool logout();

        bool changePassword();
        bool validateUser();

        void encryptFiles(QString path);
        void decryptFiles(QString path);

        int getPasswordMinLength();
        int getPasswordMinNumUpper();
        int getPasswordMinNumLower();
        QString getPasswordSpecialChars();

    private:
        PasswordManager m_pwm;
        UserManager m_um;
};