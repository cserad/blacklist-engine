#include "hashgenerator.h"

#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <QCryptographicHash>


void HashGenerator::generateHashes(const QString &filePath)
{
    QFile file(filePath);

    if (!file.open(QFile::ReadOnly)) {
        qDebug() << QStringLiteral("Couldn't open file.");
    }

    QByteArray data = file.readAll();

    file.close();

    QCryptographicHash hashMd5(QCryptographicHash::Algorithm::Md5);
    QCryptographicHash hashSha1(QCryptographicHash::Algorithm::Sha1);
    QCryptographicHash hashSha256(QCryptographicHash::Algorithm::Sha256);

    hashMd5.addData(data);
    hashSha1.addData(data);
    hashSha256.addData(data);

    hashes.clear();

    hashes.append(hashMd5.result().toHex());
    hashes.append(hashSha1.result().toHex());
    hashes.append(hashSha256.result().toHex());
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
