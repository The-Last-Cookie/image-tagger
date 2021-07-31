#include "basicfile.h"

BasicFile::BasicFile()
{

}

void BasicFile::setId(int id)
{
    if (m_id != id) {
        m_id = id;
    }
}

void BasicFile::setName(QString name)
{
    if (m_name != name) {
        m_name = name;
    }
}

void BasicFile::setFileExtension(QString fileExtension)
{
    if (m_fileExtension != fileExtension) {
        m_fileExtension = fileExtension;
    }
}

int BasicFile::getId() const
{
    return m_id;
}

QString BasicFile::getName() const
{
    return m_name;
}

QString BasicFile::getFileExtension() const
{
    return m_fileExtension;
}
