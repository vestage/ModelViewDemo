#ifndef MYDETEGATE_H
#define MYDETEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>
#include <QApplication>

class MyDetegate : public QStyledItemDelegate
{
public:
    MyDetegate(QObject *parent = nullptr);

private:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // MYDETEGATE_H
