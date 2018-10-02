#include "database.h"

Database::Database()
{
}

Database::Database(const QString &path)
{
    db = QSqlDatabase::addDatabase("QSQLITE", "blacklist.db");
    db.setDatabaseName(path);

    initDatabase();
}

bool Database::findHash(const QString &hash)
{
    QSqlQuery query;

    query.prepare("SELECT hash FROM myhashes WHERE hash = (:hash);");
    query.bindValue(":hash", hash);
    query.exec();

    return query.first();
}

void Database::initDatabase()
{

}
