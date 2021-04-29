#include "mydetegate.h"
#include <QDebug>

MyDetegate::MyDetegate(QObject *parent) : QStyledItemDelegate(parent)
{

}

void MyDetegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QString strData = index.data().toString();

    if (strData.toDouble() > 100000) {
        QStyleOptionViewItem styleOption = option;
         styleOption.displayAlignment = Qt::AlignRight;
         styleOption.palette.setColor(QPalette::Text, QColor(Qt::red));
         QApplication::style()->drawItemText(painter, styleOption.rect, styleOption.displayAlignment,
                                             styleOption.palette, true, strData, QPalette::Text);
         QStyledItemDelegate::paint(painter, styleOption, index);
    }
    else {
         QStyledItemDelegate::paint(painter, option, index);
    }
}
