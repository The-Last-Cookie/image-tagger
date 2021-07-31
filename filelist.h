#pragma once

#include <QObject>
#include <QVector>

#include "basicfile.h"

class FileList : public QObject
{
    Q_OBJECT

    public:
        explicit FileList(QObject *parent = nullptr);

        QVector<BasicFile> getItems() const;

        bool setItemAt(int index, const BasicFile &basicFile);

    signals:
        void preItemAppended();
        void postItemAppended();

        void preItemRemoved();
        void postItemRemoved();

    public slots:
        void appendItem(BasicFile basicFile);
        void removeItem(int index);

    private:
        QVector<BasicFile> m_items;
};

