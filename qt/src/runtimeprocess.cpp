#include "runtimeprocess.h"
#include <QDebug>

RuntimeProcess::RuntimeProcess(QDir bDir, QObject *) : baseDir(bDir)
{
    setWorkingDirectory(baseDir.absolutePath());
}

