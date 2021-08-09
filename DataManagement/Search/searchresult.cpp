#include "searchresult.h"

SearchResult::SearchResult()
{

}

SearchResult::~SearchResult()
{

}

BasicFile SearchResult::getFileAt(int index)
{
    if (index < 0 || index >= m_files.size()) {
        return BasicFile();
    }

    return m_files.at(index);
}

void SearchResult::appendFile(BasicFile basicFile)
{
    m_files.append(basicFile);
}

void SearchResult::removeFileAt(int index)
{
    if (index < 0 || index >= m_files.size()) {
        return;
    }

    m_files.removeAt(index);
}

bool SearchResult::isEmpty()
{
    if (m_files.isEmpty()) {
        return true;
    }

    return false;
}

void SearchResult::clear()
{
    m_files.clear();
}
