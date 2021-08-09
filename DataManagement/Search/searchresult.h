#pragma once

#include <QObject>
#include <QVector>

#include "../basicfile.h"

class SearchResult : QObject
{
    Q_OBJECT

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
