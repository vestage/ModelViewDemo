#include "zqydatasource.h"

#define TABLE_NAME "test2"

ZqyDataSource::ZqyDataSource()
{
}

QVector<QVariantList> ZqyDataSource::fetchData()
{
    ZqySqlObject sqlObject;
    QVector<QVariantList> vectorRet;

    if (!sqlObject.open())
    {
        //...此处应有报错
        return QVector<QVariantList>();
    }

     vectorRet = sqlObject.getTableValue(TABLE_NAME);
    return vectorRet;
}
