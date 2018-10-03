#pragma once

#include <QtSql>


class Database
{
public:
    Database();
    Database(const QString &path);

    void initDatabase();
    bool findHash(const QString &hash);
    bool findHash(const QStringList &hashes);
    void createTable(const QString &tableName);
    void addRecord(const QString &record);

private:
    QSqlDatabase db;
    QString table;
};
