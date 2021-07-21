#pragma once

#include <QJsonObject>

class SettingsManager
{
    public:
        SettingsManager();
        ~SettingsManager();

        QJsonObject createDefaultSettingsFile();
};

