#ifndef ZQYSQLOBJECT_H
#define ZQYSQLOBJECT_H

#include <QObject>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QVector>

class ZqySqlObject
{
public:
    ZqySqlObject();
    bool open();
    QVector<QVariantList> getTableValue(QString);

private:
    QSqlDatabase m_sqlDb;
};

#endif // ZQYSQLOBJECT_H
