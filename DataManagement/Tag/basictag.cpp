#include "basictag.h"

BasicTag::BasicTag()
{

}

BasicTag::~BasicTag()
{

}

void BasicTag::setId(int id)
{
    if (m_id != id) {
        m_id = id;
    }
}

void BasicTag::setName(QString name)
{
    if (m_name != name) {
        m_name = name;
    }
}

void BasicTag::setDescription(QString description)
{
    if (m_description != description) {
        m_description = description;
    }
}

int BasicTag::getId()
{
    return m_id;
}

QString BasicTag::getName()
{
    return m_name;
}

QString BasicTag::getDescription()
{
    return m_description;
}
