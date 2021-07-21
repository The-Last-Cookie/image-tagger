#pragma once

#include <QString>
#include <QCryptographicHash>

class PasswordManager
{
    public:
        PasswordManager();
        ~PasswordManager();

        bool checkPassword(QString password);
        QString hashPassword(QString password);
        bool comparePasswordWithHash(QString password, QString hash);

        void setMinLength(int minLength);
        void setMinNumUpper(int minNumUpper);
        void setMinNumLower(int minNumLower);
        void setSpecialChars(QString specialChars);

    private:
        int m_minLength;
        int m_minNumUpper;
        int m_minNumLower;
        QString m_specialChars;
};
