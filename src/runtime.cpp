#include "runtime.h"
#include "sconnect.h"

Runtime::Runtime(QDir runtimeDirectory) : phpProcess(runtimeDirectory), serverProcess(runtimeDirectory), goingDown(false)
{
}

Runtime::~Runtime()
{
    goingDown = true;
    phpProcess.close();
    serverProcess.close();
    phpProcess.waitForFinished();
    serverProcess.waitForFinished();
}

void Runtime::start()
{
    sconnect(&serverProcess, SIGNAL(finished(int, QProcess::ExitStatus)),
             this, SLOT(onServerProcessFinished(int, QProcess::ExitStatus)));
    sconnect(&phpProcess, SIGNAL(finished(int, QProcess::ExitStatus)),
             this, SLOT(onPhpProcessFinished(int, QProcess::ExitStatus)));

    serverProcess.start();
    phpProcess.start();
    serverProcess.waitForStarted();
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

void Runtime::onServerProcessFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    analyzeProcessShutdown(exitCode, exitStatus, "Server process");
}

void Runtime::onPhpProcessFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    analyzeProcessShutdown(exitCode, exitStatus, "Php process");
}
