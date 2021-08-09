#pragma once

#include <QString>

class BasicFile
{
    public:
        BasicFile();
        ~BasicFile();
    
        void setId(int id);
        void setName(QString name);
        void setExtension(QString extension);
    
        int getId();
        QString getName();
        QString getExtension();
    
    private:
        int m_id;
        QString m_name;
        QString m_extension;
};
