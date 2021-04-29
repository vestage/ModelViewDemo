#ifndef ZQYDATASOURCE_H
#define ZQYDATASOURCE_H

#include "zqysqlobject.h"
#include <QVector>
#include <QObject>
#include <QDebug>

class ZqyDataSource
{
public:
    ZqyDataSource();

    QVector<QVariantList> fetchData();
    int count();
};

#endif // ZQYDATASOURCE_H
