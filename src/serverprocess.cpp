#include "serverprocess.h"

ServerProcess::ServerProcess(QDir baseDir, QObject *parent) : RuntimeProcess(baseDir, parent)
{
}

void ServerProcess::start()
{
    QStringList arguments;
    arguments << "-D";
    arguments << "-f";
    arguments << "lighttpd.conf";
    QProcess::start("lighttpd", arguments);
}
