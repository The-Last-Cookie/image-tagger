#pragma once

#include <QString>
#include <QCryptographicHash>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTextStream>

class PasswordManager
{
    public:
        PasswordManager();
        ~PasswordManager();

        bool checkPassword(QString password);
        QString hashPassword(QString password);
        bool comparePasswordWithHash(QString password, QString hash);

        int getMinLength();
        int getMinNumUpper();
        int getMinNumLower();
        QString getSpecialChars();

    private:
        int m_minLength;
        int m_minNumUpper;
        int m_minNumLower;
        QString m_specialChars;
};
