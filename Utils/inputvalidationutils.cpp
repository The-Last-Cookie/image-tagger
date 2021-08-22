#include "inputvalidationutils.h"

InputValidationUtils::InputValidationUtils()
{

}

QString InputValidationUtils::sanitizeSearchArg(QString string)
{
    int countColon = string.count(":");
    for (; countColon > 1; countColon--) {
        string.remove(string.lastIndexOf(":"), 1);
    }

    // Space was filtered out in beforehand
    // See isValidString for reference
    QString notAllowedChars[] = {"\\", "/", "%", ".", "&", "\"", "'", ",", ";", "<", ">", "?", "!"};
    for (int i = 0; i < string.length(); i++) {
        QChar c = string.at(i);

        if (notAllowedChars->contains(c)) {
            string.remove(i, 1);
        }
    }

    return string;
}

bool InputValidationUtils::isValidString(QString string)
{
    if (string.isEmpty() || string.isNull()) {
        return false;
    }

    QString notAllowedChars[] = {" ", "\\", "/", "%", ".", "&", "\"", "'", ",", ";", "<", ">", "?", "!"};
    for (int i = 0; i < string.length(); i++) {
        QChar c = string.at(i);

        if (notAllowedChars->contains(c)) {
            return false;
        }
    }

    return true;
}
