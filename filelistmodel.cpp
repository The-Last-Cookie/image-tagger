#include "filelistmodel.h"

FileListModel::FileListModel(QObject *parent) : QAbstractListModel(parent), m_list(nullptr)
{

}

int FileListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !m_list) {
        return 0;
    }

    return m_list->getItems().size();
}

QVariant FileListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !m_list) {
        return QVariant();
    }

    const BasicFile basicFile = m_list->getItems().at(index.row());
    switch (role) {
        case IdRole:
            return QVariant(basicFile.getId());

        case NameRole:
            return QVariant(basicFile.getName());

        case FileExtensionRole:
            return QVariant(basicFile.getFileExtension());
    }

    return QVariant();
}

bool FileListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!m_list) {
        return false;
    }

    BasicFile basicFile = m_list->getItems().at(index.row());
    switch (role) {
        case IdRole:
            basicFile.setId(value.toInt());
            break;

        case NameRole:
            basicFile.setName(value.toString());
            break;

        case FileExtensionRole:
            basicFile.setFileExtension(value.toString());
            break;
    }

    if (m_list->setItemAt(index.row(), basicFile)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }

    return false;
}

Qt::ItemFlags FileListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid()) {
        return Qt::NoItemFlags;
    }

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> FileListModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[IdRole] = "id";
    names[NameRole] = "name";
    names[FileExtensionRole] = "fileExtension";
    return names;
}

FileList *FileListModel::getList() const
{
    return m_list;
}

void FileListModel::setList(FileList *list)
{
    beginResetModel();

    if (m_list) {
        m_list->disconnect(this);
    }

    m_list = list;

    if (m_list) {
        connect(m_list, &FileList::preItemAppended, this, [=]() {
            const int index = m_list->getItems().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(m_list, &FileList::postItemAppended, this, [=]() {
            endInsertRows();
        });

        connect(m_list, &FileList::preItemRemoved, this, [=](int index) {
            beginRemoveRows(QModelIndex(), index, index);
        });
        connect(m_list, &FileList::postItemRemoved, this, [=]() {
            endRemoveRows();
        });
    }

    endResetModel();
}


