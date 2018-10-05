#include "scanner.h"

#include <QTextStream>
#include <QDirIterator>

#include "hashgenerator.h"

Scanner::Scanner()
{
    hashDatabase = Database("/home/adam/databases/blacklist.db");
}

void Scanner::lookUp(const QString &hash)
{
    printResult(hashDatabase.findHash(hash), hash);
}

void Scanner::scanFile(const QString &filePath)
{
    HashGenerator generator;

    if (generator.generateHashes(filePath)) {

        QVariantMap hashes = generator.getHashes();

        printResult(hashDatabase.findHash(hashes), hashes.values().first().toString());


        for (const QString &key : hashes.keys()) {
            hashDatabase.addRecord(hashes.value(key).toString());
        }

    } else {
        QTextStream output(stdout);
        output << QStringLiteral("Cant open file (maybe it is a folder)\n");
        output.flush();
    }
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
        output << QStringLiteral("Result: Blocked");

        if (!hash.isEmpty()) {
            output << QStringLiteral("  Files hash: ") << hash;
        }

        output << QStringLiteral("\n");

        output.flush();
    } else {
        output << QStringLiteral("Result: No threat detected\n");
        output.flush();
    }
}
