#pragma once

#include <QString>

#include "database.h"

class Scanner
{
public:
    Scanner();
    void lookUp(const QString &hash);
    void scanFile(const QString &filePath);
    void scanFolder(const QString &folderPath);

private:
    void printResult(bool success, const QString &hash = "");

private:
    Database hashDatabase;
};
