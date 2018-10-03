#pragma once

#include <QStringList>

class HashGenerator
{
public:
    bool generateHashes(const QString &filePath);
    void printHashes();
    QStringList getHashes();

private:
    QStringList hashes;
};
