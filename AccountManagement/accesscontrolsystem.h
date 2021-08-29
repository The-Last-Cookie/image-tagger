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
        static AccessControlSystem &instance();
        ~AccessControlSystem();

    public slots:
        bool createUser(QString username, QString password);
        void deleteUser();

        bool login(QString username, QString password);
        void logout();

        bool changePassword(QString oldPassword, QString newPassword, QString newPasswordConfirm);

        // TODO: make methods in PasswordManager static, so that these methods can get moved to TextProviderUtils
        int getPasswordMinLength();
        int getPasswordMinNumUpper();
        int getPasswordMinNumLower();
        QString getPasswordSpecialChars();
        QString getPasswordRulesText();

        QString getSessionPath();

    private:
        explicit AccessControlSystem(QObject *parent = nullptr);
        static AccessControlSystem* m_instance;

        void encryptFiles(QString path);
        void decryptFiles(QString path);

        PasswordManager m_pwm;
        UserManager m_um;
        Session m_session;
};
