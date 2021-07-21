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
#include "usermanager.h"

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

    private:
        PasswordManager m_pwm;
        UserManager m_um;
};
