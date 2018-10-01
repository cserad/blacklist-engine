#include "scanner.h"

#include <QTextStream>
#include <QDirIterator>

#include "hashgenerator.h"

Scanner::Scanner(const QString &dbPath)
{
    hashDatabase.initDatabase(dbPath);
}

void Scanner::lookUp(const QString &hash)
{
    printResult(hashDatabase.findHash(hash), hash);
}

void Scanner::scanFile(const QString &filePath)
{
    bool blocked = false;
    HashGenerator generator;

    generator.generateHashes(filePath);

    QStringList hashes = generator.getHashes();

    auto it = hashes.begin();

    while (!blocked && it!=hashes.end()) {
        blocked = hashDatabase.findHash(*it);
        it++;
    }
    it--;

    printResult(blocked, *it);
}

void Scanner::scanFolder(const QString &folderPath)
{
    QDirIterator folder(folderPath);

    while (folder.hasNext()) {
        scanFile(folder.next());
    }
}

void Scanner::printResult(bool blocked, const QString &hash)
{
    QTextStream output(stdout);

    if (blocked) {
        output << QStringLiteral("Result: Blocked   Files hash: ") << hash << QStringLiteral("\n");
        output.flush();
    } else {
        output << QStringLiteral("Result: No threat detected\n");
        output.flush();
    }
}
