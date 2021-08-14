#pragma once

#include <QString>

class BasicTag
{
    public:
        BasicTag();
        ~BasicTag();

        void setId(int id);
        void setName(QString name);
        void setDescription(QString description);

        int getId();
        QString getName();
        QString getDescription();

    private:
        int m_id;
        QString m_name;
        QString m_description;
};
