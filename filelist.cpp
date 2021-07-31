#include "filelist.h"

FileList::FileList(QObject *parent) : QObject(parent)
{
    // test data
    BasicFile file;
    file.setId(10);
    m_items.append(file);
}

QVector<BasicFile> FileList::getItems() const
{
    return m_items;
}

bool FileList::setItemAt(int index, const BasicFile &basicFile)
{
    if (index < 0 || index >= m_items.size()) {
        return false;
    }

    const BasicFile oldFile = m_items.at(index);
    if (basicFile.getId() == oldFile.getId()) {
        return false;
    }

    m_items[index] = basicFile;
    return true;
}

void FileList::appendItem(BasicFile basicFile)
{
    emit preItemAppended();

    m_items.append(basicFile);

    emit postItemAppended();
}

void FileList::removeItem(int index)
{
    emit preItemRemoved();

    m_items.removeAt(index);

    emit postItemRemoved();
}
