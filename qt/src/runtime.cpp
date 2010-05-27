#include "runtime.h"
#include "sconnect.h"

Runtime::Runtime(QDir runtimeDirectory) : phpProcess(runtimeDirectory), goingDown(false)
{
}

Runtime::~Runtime()
{
    goingDown = true;
    phpProcess.close();
    phpProcess.waitForFinished();
}

void Runtime::start()
{
    sconnect(&phpProcess, SIGNAL(finished(int, QProcess::ExitStatus)),
             this, SLOT(onPhpProcessFinished(int, QProcess::ExitStatus)));

    phpProcess.start();
    phpProcess.waitForStarted();
}

void Runtime::analyzeProcessShutdown(int exitCode, QProcess::ExitStatus exitStatus, QString name)
{
    if (goingDown)
        return;

    if (exitStatus == QProcess::CrashExit) {
        qDebug() << name << "crashed unexpectedly. Exit code:" << exitCode;
    } else {
        qDebug() << name << "quit unexpectedly. Exit code:" << exitCode;
    }

}

void Runtime::onPhpProcessFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    analyzeProcessShutdown(exitCode, exitStatus, "Php process");
}
