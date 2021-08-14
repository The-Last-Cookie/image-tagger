#include "basicauthor.h"

BasicAuthor::BasicAuthor()
{

}

BasicAuthor::~BasicAuthor()
{

}

void BasicAuthor::setId(int id)
{
    if (m_id != id) {
        m_id = id;
    }
}

void BasicAuthor::setName(QString name)
{
    if (m_name != name) {
        m_name = name;
    }
}

void BasicAuthor::setDescription(QString description)
{
    if (m_description != description) {
        m_description = description;
    }
}

int BasicAuthor::getId()
{
    return m_id;
}

QString BasicAuthor::getName()
{
    return m_name;
}

QString BasicAuthor::getDescription()
{
    return m_description;
}
