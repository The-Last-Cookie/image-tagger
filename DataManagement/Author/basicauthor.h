#pragma once

#include <QString>

class BasicAuthor
{
    public:
        BasicAuthor();
        ~BasicAuthor();

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
