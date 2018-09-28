#include "database.h"

Database::Database(const QString &path)
{
    initDatabase(path);
}

bool Database::findHash(const QString &hash)
{
    QSqlQuery query;

    query.prepare("SELECT hash FROM myhashes WHERE hash = (:hash);");
    query.bindValue(":hash", hash);
    query.exec();

    return query.first();
}

void Database::initDatabase(const QString &path)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    if (!db.open()) {
        qDebug() << "Error: cannot connect to database";
    } else {
        qDebug() << "ok";
    }
}
