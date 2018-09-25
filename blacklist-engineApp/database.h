#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>


class Database
{
private:
    QSqlDatabase db;
public:
    Database();
};

#endif // DATABASE_H
