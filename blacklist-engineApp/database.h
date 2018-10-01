#pragma once

#include <QtSql>


class Database
{
public:
    Database();
    void initDatabase(const QString &path);
    bool findHash(const QString &hash);

private:
    QSqlDatabase db;
};
