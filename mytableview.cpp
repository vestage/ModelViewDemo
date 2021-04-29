#include "mytableview.h"

MyTableView::MyTableView(QWidget *parent)
    : QTableView(parent)
{
    horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    setAlternatingRowColors(true);

    QFile qss(":tableview.qss");
    if( qss.open(QFile::ReadOnly) )
    {
        QString strStyle = QLatin1String(qss.readAll());
        setStyleSheet(strStyle);
        qss.close();
    } else {
        qDebug("Open failed");
    }
}

