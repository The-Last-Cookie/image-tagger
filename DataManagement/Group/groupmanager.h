#pragma once

#include <QObject>

#include "AccountManagement/accesscontrolsystem.h"
#include "databasemanager.h"

class GroupManager : public QObject
{
    Q_OBJECT

    public:
        explicit GroupManager(QObject *parent = nullptr);
        ~GroupManager();

    public slots:
        bool createGroup(QString name, QString description);
        void addGroupToFile(int groupId, int fileId);
        bool deleteGroup(int groupId);
};
