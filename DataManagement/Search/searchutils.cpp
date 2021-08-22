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
    QString finishedQuery;

    QueryCreationUtils queryUtils;
    queryUtils.prepareFileString();

    if (args.size() == 0) {
        finishedQuery = queryUtils.finishQueryCreation();
        return finishedQuery;
    }

    // Check if JOINS in the SELECT statement are needed
    for (int i = 0; i < args.size(); i++) {
        QString keyword = getKeyword(args.at(i));
        if (keyword == "t") {
            queryUtils.prepareTagString();
            break;
        }
    }

    for (int i = 0; i < args.size(); i++) {
        QString keyword = getKeyword(args.at(i));
        if (keyword == "a") {
            queryUtils.prepareAuthorString();
            break;
        }
    }

    for (int i = 0; i < args.size(); i++) {
        QString keyword = getKeyword(args.at(i));
        if (keyword == "g") {
            queryUtils.prepareGroupString();
            break;
        }
    }

    queryUtils.finishPreparation();
    queryUtils.prepareAddingArguments();

    // Add all arguments
    bool oneArgOrMoreAppended = false;
    for (int i = 0; i < args.size(); i++) {
        QString keyword = getKeyword(args.at(i));
        if (keyword == "" || keyword == "name") {
            if (oneArgOrMoreAppended) {
                queryUtils.addAndOperator();
            }

            queryUtils.addArgument(QueryCreationUtils::Filename);
            oneArgOrMoreAppended = true;
        }

        else if (keyword == "ext") {
            if (oneArgOrMoreAppended) {
                queryUtils.addAndOperator();
            }

            queryUtils.addArgument(QueryCreationUtils::Extension);
            oneArgOrMoreAppended = true;
        }

        else if (keyword == "added") {
            if (oneArgOrMoreAppended) {
                queryUtils.addAndOperator();
            }

            queryUtils.addArgument(QueryCreationUtils::Date);
            oneArgOrMoreAppended = true;
        }

        else if (keyword == "size") {
            if (oneArgOrMoreAppended) {
                queryUtils.addAndOperator();
            }

            queryUtils.addArgument(QueryCreationUtils::Size);
            oneArgOrMoreAppended = true;
        }

        else if (keyword == "t") {
            if (oneArgOrMoreAppended) {
                queryUtils.addAndOperator();
            }

            queryUtils.addArgument(QueryCreationUtils::Tag);
            oneArgOrMoreAppended = true;
        }

        else if (keyword == "a") {
            if (oneArgOrMoreAppended) {
                queryUtils.addAndOperator();
            }

            queryUtils.addArgument(QueryCreationUtils::Author);
            oneArgOrMoreAppended = true;
        }

        else if (keyword == "g") {
            if (oneArgOrMoreAppended) {
                queryUtils.addAndOperator();
            }

            queryUtils.addArgument(QueryCreationUtils::Group);
            oneArgOrMoreAppended = true;
        }
    }

    finishedQuery = queryUtils.finishQueryCreation();
    return finishedQuery;
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
            || c == "#") {
            string.remove(i, 1);
        }
    }

    return string;
}
