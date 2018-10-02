#include "hashgenerator.h"

#include <QTextStream>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QCryptographicHash>


void HashGenerator::generateHashes(const QString &filePath)
{
    QFile file(filePath);
    QFileInfo info(file);

    if (info.isFile() && file.open(QFile::ReadOnly)) {
        QByteArray data = file.readAll();

        file.close();

        hashes.clear();

        hashes.append(QCryptographicHash::hash(data, QCryptographicHash::Algorithm::Md5).toHex());
        hashes.append(QCryptographicHash::hash(data, QCryptographicHash::Algorithm::Sha1).toHex());
        hashes.append(QCryptographicHash::hash(data, QCryptographicHash::Algorithm::Sha256).toHex());
    }
}

void HashGenerator::printHashes()
{
    QTextStream output(stdout);

    output << QStringLiteral("MD5: ") << hashes[0] << QStringLiteral("\n");
    output << QStringLiteral("SHA1: ") << hashes[1] << QStringLiteral("\n");
    output << QStringLiteral("SHA256: ") << hashes[2] << QStringLiteral("\n");

    output.flush();
}

QStringList HashGenerator::getHashes()
{
    return hashes;
}
