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
#include "AccountManagement/session.h"

class AccessControlSystem : public QObject
{
    Q_OBJECT

    public:
        AccessControlSystem();
        ~AccessControlSystem();

    public slots:
        bool createUser(QString username, QString password);
        void deleteUser();

        bool login(QString username, QString password);
        void logout();

        bool changePassword(QString oldPassword, QString newPassword, QString newPasswordConfirm);

        void encryptFiles(QString path);
        void decryptFiles(QString path);

        int getPasswordMinLength();
        int getPasswordMinNumUpper();
        int getPasswordMinNumLower();
        QString getPasswordSpecialChars();

        QString getSessionPath();

    private:
        PasswordManager m_pwm;
        UserManager m_um;
        Session m_session;
};
