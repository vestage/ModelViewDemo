#ifndef MYTABLEMODEL_H
#define MYTABLEMODEL_H

#include <QObject>
#include <QVector>
#include <QAbstractTableModel>

class MyTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    MyTableModel(QObject *parent = nullptr);

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void setVec(QVector<QVariantList>);

private:
    QStringList m_strlistHeaders;
    QVector<QVariantList> m_vecData;
};

#endif // MYTABLEMODEL_H
