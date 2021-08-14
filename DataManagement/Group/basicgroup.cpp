#include "basicgroup.h"

BasicGroup::BasicGroup()
{

}

BasicGroup::~BasicGroup()
{

}

void BasicGroup::setId(int id)
{
    if (m_id != id) {
        m_id = id;
    }
}

void BasicGroup::setName(QString name)
{
    if (m_name != name) {
        m_name = name;
    }
}

void BasicGroup::setDescription(QString description)
{
    if (m_description != description) {
        m_description = description;
    }
}

int BasicGroup::getId()
{
    return m_id;
}

QString BasicGroup::getName()
{
    return m_name;
}

QString BasicGroup::getDescription()
{
    return m_description;
}
