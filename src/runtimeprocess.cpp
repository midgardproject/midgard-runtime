#include "runtimeprocess.h"
#include <QDebug>

RuntimeProcess::RuntimeProcess(QDir bDir, QObject *parent) : baseDir(bDir)
{
    setWorkingDirectory(baseDir.absolutePath());
}

