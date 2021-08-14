#pragma once

#include <QString>

class QueryCreationUtils
{
    public:
        QueryCreationUtils();
        ~QueryCreationUtils();

        enum ArgumentType {
            Filename,
            Extension,
            Size,
            Date,
            Tag,
            Author,
            Group
        };

        void prepareFileString();
        void prepareTagString();
        void prepareAuthorString();
        void prepareGroupString();

        void addArgument(ArgumentType argType);

        void addAndOperator();

        void finishPreparation();
        void prepareAddingArguments();
        QString finishQueryCreation();

    private:
        QString m_query;

        bool m_addTag;
        bool m_addAuthor;
        bool m_addGroup;
};
