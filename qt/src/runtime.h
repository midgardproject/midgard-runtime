#include <QObject>
#include <QProcess>
#include <QDir>
#include "phpprocess.h"

#ifndef RUNTIME_H
#define RUNTIME_H

class Runtime : public QObject
{
    Q_OBJECT

public:
    explicit Runtime(QDir dir);
    ~Runtime();
    void start();

private:
    PhpProcess phpProcess;
    bool goingDown;
    void analyzeProcessShutdown(int exitCode, QProcess::ExitStatus exitStatus, QString name);

private slots:
    void onPhpProcessFinished(int exitCode, QProcess::ExitStatus exitStatus);
};

#endif

