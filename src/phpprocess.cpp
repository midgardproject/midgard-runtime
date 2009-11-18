#include "phpprocess.h"
#include <QDebug>

PhpProcess::PhpProcess(QDir baseDir, QObject *parent) : RuntimeProcess(baseDir, parent)
{
}

void PhpProcess::start()
{
    QStringList arguments;
    QStringList env;

    arguments << "-b";
    arguments << "127.0.0.1:9000";

    env << ("MIDGARD_ENV_GLOBAL_CACHEDIR=" + baseDir.absoluteFilePath("cache"));
    env << ("MIDGARD_ENV_GLOBAL_SHAREDIR=" + baseDir.absoluteFilePath("share"));
    setEnvironment(env);
    QProcess::start("php5-cgi", arguments);
}
