#pragma once

#include <QObject>

#include "AccountManagement/accesscontrolsystem.h"
#include "databasemanager.h"
#include "Utils/inputvalidationutils.h"

class TagManager : public QObject
{
    Q_OBJECT

    public:
        explicit TagManager(QObject *parent = nullptr);
        ~TagManager();

    public slots:
        bool createTag(QString name, QString description);
        void addTagToFile(int tagId, int fileId);
        bool deleteTag(int tagId);
};
