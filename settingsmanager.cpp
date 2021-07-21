#include "settingsmanager.h"

SettingsManager::SettingsManager()
{

}

SettingsManager::~SettingsManager()
{

}

QJsonObject SettingsManager::createDefaultSettingsFile()
{
    QJsonObject settings;
    settings.insert("theme", "white");

    return settings;
}
