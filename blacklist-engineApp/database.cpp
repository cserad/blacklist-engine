#include "database.h"

#include <QStringList>

Database::Database()
{
}

Database::Database(const QString &path)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    initDatabase();
}

bool Database::findHash(const QString &hash)
{
    QSqlQuery query(db);

    query.prepare("SELECT hash FROM " + table + " WHERE hash = (:hash);");

    query.bindValue(":hash", hash);

    query.exec();

    return query.first();
}

bool Database::findHash(const QStringList &hashes)
{
    QSqlQuery query(db);

    query.prepare("SELECT hash FROM " + table +
                  " WHERE hash = (:hashmda5)"
                    "OR hash = (:hashsha1)"
                    "OR hash = (:hashsha256)");

    query.bindValue(":hashmd5", hashes[0]);
    query.bindValue(":hashsha1", hashes[1]);
    query.bindValue(":hashsha256", hashes[2]);

    query.exec();

    return query.first();
}

void Database::createTable(const QString &tableName)
{
    QSqlQuery query;


    query.prepare("CREATE TABLE IF NOT EXISTS" + tableName + " ("
                  "hash text PRIMARY KEY)");

    query.exec();
}

void Database::addRecord(const QString &record)
{
    QSqlQuery query;

    query.prepare("INSERT INTO " + table + " VALUES (:record)");

    query.bindValue(":record", record);
    query.exec();
}

void Database::initDatabase()
{
    if (db.open()) {
        QStringList tables = db.tables();

        if (tables.isEmpty()) {
            createTable(QStringLiteral("Blocked"));
            table = QStringLiteral("Blocked");

            addRecord("asd");

            return;
        } else {
            table = tables.first();

            return;
        }
    } else {
        QTextStream output(stdout);
        output << QStringLiteral("Couldn't connect to database");
        output.flush();

        return;
    }
}
