#ifndef MYTABLEVIEW_H
#define MYTABLEVIEW_H

#include <QTableView>
#include <QHeaderView>
#include <QFile>

class MyTableView : public QTableView
{
public:
    MyTableView(QWidget *parent = nullptr);
};

#endif // MYTABLEVIEW_H
