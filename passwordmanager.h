#pragma once

#include <iostream>

class PasswordManager
{
    public:
        PasswordManager();
        ~PasswordManager();

        bool checkPassword(std::string password);
        std::string hashPassword(std::string password);
        bool comparePasswordWithHash(std::string password, std::string hash);

        void setMinLength(int minLength);
        void setMinNumUpper(int minNumUpper);
        void setMinNumLower(int minNumLower);
        void setSpecialChars(std::string specialChars);

    private:
        int m_minLength;
        int m_minNumUpper;
        int m_minNumLower;
        std::string m_specialChars;
};

