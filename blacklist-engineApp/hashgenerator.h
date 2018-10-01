#pragma once

#include <QStringList>

class HashGenerator
{
public:
    void generateHashes(const QString &filePath);
    void printHashes();
    QStringList getHashes();

private:
    QStringList hashes;
};
