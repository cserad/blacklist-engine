#include <QCoreApplication>
#include <QCommandLineParser>

#include "database.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    app.setApplicationName(QStringLiteral("Blacklist engine"));
    app.setApplicationVersion(QStringLiteral("1.0"));

    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();

    QCommandLineOption scanOption(QStringList() << "s" << "scan", QStringLiteral("Generates hash for file and scan it."), "scan");
    parser.addOption(scanOption);

    QCommandLineOption lookupOption(QStringList() << "l" << "lookup", QStringLiteral("Scans given hash."), "lookup");
    parser.addOption(lookupOption);

    QCommandLineOption generateOption(QStringList() << "g" << "generate", QStringLiteral("Generates hashes for file and write them on the console."), "generate");
    parser.addOption(generateOption);

    QCommandLineOption folderOption(QStringList() << "f" << "folder", QStringLiteral("Scans files in the given folder."), "folder");
    parser.addOption(folderOption);

    parser.process(app);

    Database myDB("/home/adam/databases/hashes.db");

    QTextStream output(stdout);

    if (myDB.findHash("eed675abe602b0990ee3d4dcc0d72b14")) {
        output << "eed675abe602b0990ee3d4dcc0d72b14 in db \n";
        output.flush();
    } else {
        output << "eed675abe602b0990ee3d4dcc0d72b14 not in db \n";
        output.flush();
    }

    if (myDB.findHash("eed675abe602b0990ee3d4dcc0d72b18")) {
        output << "eed675abe602b0990ee3d4dcc0d72b18 in db \n";
        output.flush();
    } else {
        output << "eed675abe602b0990ee3d4dcc0d72b18 not in db \n";
        output.flush();
    }

    return app.exec();
}
