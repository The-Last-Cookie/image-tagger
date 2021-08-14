#pragma once

#include <QString>

class BasicGroup
{
    public:
        BasicGroup();
        ~BasicGroup();

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
