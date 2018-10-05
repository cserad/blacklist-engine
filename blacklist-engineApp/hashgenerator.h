#pragma once

#include <QVariantMap>

class HashGenerator
{
public:
    bool generateHashes(const QString &filePath);
    void printHashes();
    QVariantMap getHashes();

private:
    QVariantMap hashes;
};
