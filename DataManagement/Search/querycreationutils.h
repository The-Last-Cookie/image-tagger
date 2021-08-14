#pragma once

#include <QString>

class QueryCreationUtils
{
    public:
        QueryCreationUtils();
        ~QueryCreationUtils();

        enum ArgumentType {
            Name,
            Extension,
            Size,
            Date
        };

        void prepareFileString();
        void prepareTagString();
        void prepareAuthorString();
        void prepareGroupString();

        void addFileArgument(ArgumentType argType);

        void addTagArgument();

        void addAuthorArgument();

        void addGroupArgument();

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
