#pragma once

#include <QtSql>


class Database
{
public:
    Database();
    Database(const QString &path);
    void initDatabase();
    bool findHash(const QString &hash);

private:
    QSqlDatabase db;
};
