#pragma once

#include <QAbstractListModel>

#include "filelist.h"

class FileListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(FileList *fileListView READ getFileListView WRITE setFileListView)

    public:
        explicit FileListModel(QObject *parent = nullptr);

        enum {
            IdRole = Qt::UserRole,
            NameRole,
            FileExtensionRole
        };

        int rowCount(const QModelIndex &parent = QModelIndex()) const override;

        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

        bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

        Qt::ItemFlags flags(const QModelIndex &index) const override;

        virtual QHash<int, QByteArray> roleNames() const override;

        FileList *getList() const;
        void setList(FileList *list);

    private:
        FileList *m_list;
};
