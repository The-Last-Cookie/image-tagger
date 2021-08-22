#pragma once

#include <QString>

class InputValidationUtils
{
    public:
        InputValidationUtils();

        static QString sanitizeSearchArg(QString string);
        static bool isValidString(QString string);
};
