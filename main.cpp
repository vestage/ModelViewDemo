#include <QDebug>
#include <QApplication>
#include "zqydatasource.h"
#include "mytablemodel.h"
#include "mytableview.h"
#include "mydetegate.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyTableView tableView;

    MyTableModel tableModel;

    MyDetegate* pDelegate = new MyDetegate();

    ZqyDataSource dataSource;

    tableModel.setVec(dataSource.fetchData());

    tableView.setModel(&tableModel);

    tableView.setItemDelegate(pDelegate);

    tableView.resize(1000,600);

    tableView.show();

    return a.exec();
}
