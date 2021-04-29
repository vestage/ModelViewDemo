#include "mytablemodel.h"

MyTableModel::MyTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    m_strlistHeaders << "客户名称" << "证件号码" << "银行卡数量" << "关联人员数"
                          << "交易总额" << "交易总笔数" << "资金流入总额" << "资金流入总次数"
                          << "资金流出总额" << "资金流出总次数" << "交易净额" << "存现总额"
                          << "取现总额" << "转账总额" << "最早交易日期" << "最晚交易日期";
}

QVariant MyTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
    {
        return QVariant();
    }

    if (orientation == Qt::Vertical) {
           return section;
    }
    else if (orientation == Qt::Horizontal)
    {
         return m_strlistHeaders[section];
    }
}

int MyTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_vecData.count();
}

int MyTableModel::columnCount(const QModelIndex &parent) const
{
    return m_strlistHeaders.count();
}

QVariant MyTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::TextAlignmentRole)
    {
        return int(Qt::AlignRight | Qt::AlignVCenter);
    }
    else if (role == Qt::DisplayRole)
    {
        int row = index.row();
        int column = index.column();
        QVariant strRet = m_vecData[row][column];

        return strRet;
    }

    return QVariant();
}

 void MyTableModel::setVec(QVector<QVariantList> vecData)
{
     beginResetModel();
     m_vecData = vecData;
     endResetModel();
}
