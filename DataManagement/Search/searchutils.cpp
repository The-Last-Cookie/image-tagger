#include "searchutils.h"

SearchUtils::SearchUtils()
{

}

SearchUtils::~SearchUtils()
{

}

QVector<QString> SearchUtils::toSingleArgs(QString query)
{
    QVector<QString> args;

    while (query.length() != 0) {
        // Remove whitespace at the beginning and the end
        while (query.at(0) == " ") {
            query.remove(0, 1);
        }
        while (query.at(query.length() - 1) == " ") {
            query.remove(query.length() - 1, 1);
        }

        int const position = query.lastIndexOf(" ");
        if (position == -1) {
            args.append(query);
            break;
        }

        // Write next argument in temp variable
        QString temp = query.mid(position + 1, query.length() - position + 1);
        query.remove(position, temp.length() + 1);

        temp = sanitizeArg(temp);

        args.append(temp);
    }

    return args;
}

QString SearchUtils::convertToSqlQuery(QVector<QString> args)
{
    QString query = "SELECT fileId, name, extension FROM files files";

    if (args.size() == 0) {
        query.append(";");
        return query;
    } else {
        query.append(" WHERE ");
    }

    // Add keywords related to files and tags to query
    bool oneArgOrMoreAppended = false;
    for (int i = 0; i < args.size(); i++) {
        QString keyword = getKeyword(args.at(i));
        if (keyword == "" || keyword == "name") {
            if (oneArgOrMoreAppended) {
                query.append(" AND ");
            }

            query.append("files.name LIKE ?");
            oneArgOrMoreAppended = true;
        }

        if (keyword == "ext") {
            if (oneArgOrMoreAppended) {
                query.append(" AND ");
            }

            query.append("files.extension LIKE ?");
            oneArgOrMoreAppended = true;
        }

        // TODO: add added and size via bindValue
        /*if (keyword == "added") {
            if (oneArgOrMoreAppended) {
                query.append(" AND ");
            }

            query.append("files.added = \"" + getValue(args.at(i)) + "\"");
            oneArgOrMoreAppended = true;
        }

        if (keyword == "size") {
            if (oneArgOrMoreAppended) {
                query.append(" AND ");
            }

            query.append("files.size = " + getValue(args.at(i)));
            oneArgOrMoreAppended = true;
        }*/
    }
    oneArgOrMoreAppended = false;

    // Add keywords related to files and tags
    for (int i = 0; i < args.size(); i++) {
        QString keyword = getKeyword(args.at(i));
        if (keyword == "t") {
            if (oneArgOrMoreAppended) {
                query.append(" AND ");
            } else {
                query.append(" UNION SELECT fileId, name, extension FROM files files "
                             "INNER JOIN files_tags f_t INNER JOIN tags tags "
                             "ON files.fileId = f_t.fileId "
                             "AND tags.tagId = f_t.tagId WHERE ");
            }

            query.append("tags.name LIKE ?");
            oneArgOrMoreAppended = true;
        }
    }
    oneArgOrMoreAppended = false;

    // Add keywords related to files and authors
    for (int i = 0; i < args.size(); i++) {
        QString keyword = getKeyword(args.at(i));
        if (keyword == "a") {
            if (oneArgOrMoreAppended) {
                query.append(" AND ");
            } else {
                query.append(" UNION SELECT fileId, name, extension FROM files files "
                             "INNER JOIN files_tags f_t INNER JOIN authors authors "
                             "ON files.fileId = f_t.fileId "
                             "AND authors.authorId = f_t.authorId WHERE ");
            }

            query.append("authors.name LIKE ?");
            oneArgOrMoreAppended = true;
        }
    }
    oneArgOrMoreAppended = false;

    // Add keywords related to files and groups
    for (int i = 0; i < args.size(); i++) {
        QString keyword = getKeyword(args.at(i));
        if (keyword == "g") {
            if (oneArgOrMoreAppended) {
                query.append(" AND ");
            } else {
                query.append(" UNION SELECT fileId, name, extension FROM files files "
                             "INNER JOIN files_tags f_t INNER JOIN groups groups "
                             "ON files.fileId = f_t.fileId "
                             "AND groups.groupId = f_t.groupId WHERE ");
            }

            query.append("groups.name LIKE ?");
            oneArgOrMoreAppended = true;
        }
    }

    query.append(";");
    return query;
}

bool SearchUtils::hasKeyword(QString string) {
    int const position = string.lastIndexOf(":");

    if (position == -1) {
        return false;
    }

    return true;
}

QString SearchUtils::getKeyword(QString string)
{
    if (!hasKeyword(string)) {
        return "";
    }

    int const position = string.lastIndexOf(":");
    return string.mid(0, position);
}

QString SearchUtils::getValue(QString string)
{
    int const position = string.lastIndexOf(":");

    if (position == -1) {
        return string;
    }

    return string.mid(position + 1, string.length() - position + 1);
}

QString SearchUtils::sanitizeArg(QString string)
{
    while (string.count(":") > 1) {
        string.remove(string.lastIndexOf(":"), 1);
    }

    for (int i = 0; i < string.length(); i++) {
        QChar c = string.at(i);

        if (c == "*"
            || c == "+"
            || c == "\\"
            || c == "/"
            || c == "#"
            || c == "_") {
            string.remove(i, 1);
        }
    }

    return string;
}
