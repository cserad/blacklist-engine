#pragma once

#include <QtSql>


class Database
{
public:
    Database(const QString &path);
    bool findHash(const QString &hash);

private:
    void initDatabase(const QString &path);

private:
    QSqlDatabase db;
};
