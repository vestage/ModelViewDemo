#include "zqysqlobject.h"
#include <QDebug>

#define DATABASE_NAME "test.db"
#define TABLE_SIZE 16

ZqySqlObject::ZqySqlObject()
{
    m_sqlDb = QSqlDatabase::addDatabase("QSQLITE");
    m_sqlDb.setDatabaseName(DATABASE_NAME);
}

bool ZqySqlObject::open()
{
    if (!m_sqlDb.open())
    {
        return false;
    }

    return true;
}

QVector<QVariantList> ZqySqlObject::getTableValue(QString strTableName)
{   
    QVector<QVariantList> vectorRet;

    QSqlQuery query(m_sqlDb);

    query.exec(QString("select * from %1").arg(strTableName));

    while(query.next())
    {
        QVariantList varListTemp;

        for(int i = 0; i < TABLE_SIZE; i++)
        {
            varListTemp << query.value(i);
        }

        vectorRet << varListTemp;
    }

    return vectorRet;
}
