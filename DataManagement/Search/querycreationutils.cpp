#include "querycreationutils.h"

QueryCreationUtils::QueryCreationUtils()
{
    m_addTag = false;
    m_addAuthor = false;
    m_addGroup = false;
}

QueryCreationUtils::~QueryCreationUtils()
{

}

void QueryCreationUtils::prepareFileString()
{
    m_query.append("SELECT fileId, name, extension FROM files files ");
}

void QueryCreationUtils::prepareTagString()
{
    m_addTag = true;
    m_query.append("INNER JOIN files_tags f_t INNER JOIN tags tags ");
}

void QueryCreationUtils::prepareAuthorString()
{
    m_addAuthor = true;
    m_query.append("INNER JOIN files_authors f_a INNER JOIN authors authors ");
}

void QueryCreationUtils::prepareGroupString()
{
    m_addGroup = true;
    m_query.append("INNER JOIN files_groups f_g INNER JOIN groups groups ");
}

void QueryCreationUtils::addArgument(QueryCreationUtils::ArgumentType argType)
{
    switch (argType) {
        case Filename:
            m_query.append("files.name LIKE ?");
            break;

        case Extension:
            m_query.append("files.extension LIKE ?");
            break;

        case Size:
            m_query.append("files.size = ?");
            break;

        case Date:
            m_query.append("files.added = ?");
            break;

        case Tag:
            m_query.append("tags.name LIKE ?");
            break;

        case Author:
            m_query.append("authors.name LIKE ?");
            break;

        case Group:
            m_query.append("groups.name LIKE ?");
            break;

        default:
            break;
    }
}

void QueryCreationUtils::addAndOperator()
{
    m_query.append(" AND ");
}

void QueryCreationUtils::finishPreparation()
{
    m_query.append("ON ");
    bool oneArgOrMoreAppended = false;

    if (m_addTag) {
        m_query.append("files.fileId = f_t.fileId "
                       "AND tags.tagId = f_t.tagId ");
        oneArgOrMoreAppended = true;
    }

    if (m_addAuthor) {
        if (oneArgOrMoreAppended) {
            m_query.append("AND ");
        }

        m_query.append("files.fileId = f_a.fileId "
                       "AND authors.authorId = f_a.authorId ");
        oneArgOrMoreAppended = true;
    }

    if (m_addGroup) {
        if (oneArgOrMoreAppended) {
            m_query.append("AND ");
        }

        m_query.append("files.fileId = f_g.fileId "
                       "AND groups.groupId = f_g.groupId ");
    }
}

void QueryCreationUtils::prepareAddingArguments()
{
    m_query.append("WHERE ");
}

QString QueryCreationUtils::finishQueryCreation()
{
    m_query.append(";");
    return m_query;
}
