#pragma once

#include <QVector>

#include "../basicfile.h"

class SearchResult
{
    public:
        SearchResult();
        ~SearchResult();

        BasicFile getFileAt(int index);
        void appendFile(BasicFile basicFile);
        void removeFileAt(int index);

        bool isEmpty();
        void clear();

    private:
        QVector<BasicFile> m_files;
};
