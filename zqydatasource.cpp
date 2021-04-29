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
        //...�˴�Ӧ�б���
        return QVector<QVariantList>();
    }

     vectorRet = sqlObject.getTableValue(TABLE_NAME);
    return vectorRet;
}
