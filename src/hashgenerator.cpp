#include "hashgenerator.h"

#include <QTextStream>
#include <QFile>
#include <QFileInfo>
#include <QCryptographicHash>


bool HashGenerator::generateHashes(const QString &filePath)
{
    QFile file(filePath);
    QFileInfo info(file);

    if (info.isFile() && file.open(QFile::ReadOnly)) {
        QByteArray data = file.readAll();

        file.close();

        hashes.clear();

        hashes.insert(QStringLiteral("MD5"), QCryptographicHash::hash(data, QCryptographicHash::Algorithm::Md5).toHex());
        hashes.insert(QStringLiteral("SHA1"), QCryptographicHash::hash(data, QCryptographicHash::Algorithm::Sha1).toHex());
        hashes.insert(QStringLiteral("SHA256"), QCryptographicHash::hash(data, QCryptographicHash::Algorithm::Sha256).toHex());

        return true;
    } else {
        return false;
    }
}

void HashGenerator::printHashes()
{
    QTextStream output(stdout);

    for (auto it : hashes.keys()) {
        output << it << QStringLiteral(": ") << hashes.value(it).toString() << QStringLiteral("\n");
    }

    output.flush();
}

QVariantMap HashGenerator::getHashes()
{
    return hashes;
}
