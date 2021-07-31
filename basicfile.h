#pragma once

#include <QString>

class BasicFile
{
    public:
        BasicFile();
        ~BasicFile();

        void setId(int id);
        void setName(QString name);
        void setFileExtension(QString fileExtension);

        int getId() const;
        QString getName() const;
        QString getFileExtension() const;

    private:
        int m_id;
        QString m_name;
        QString m_fileExtension;
};

