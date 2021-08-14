#include "basicfile.h"

BasicFile::BasicFile()
{

}

BasicFile::~BasicFile()
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

void BasicFile::setExtension(QString extension)
{
    if (m_extension != extension) {
        m_extension = extension;
    }
}

int BasicFile::getId()
{
    return m_id;
}

QString BasicFile::getName()
{
    return m_name;
}

QString BasicFile::getExtension()
{
    return m_extension;
}
