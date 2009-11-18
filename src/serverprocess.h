#include <QObject>
#include <QProcess>
#include <QDir>
#include "runtimeprocess.h"

#ifndef SERVERPROCESS_H
#define SERVERPROCESS_H

class ServerProcess : public RuntimeProcess
{
    Q_OBJECT

public:
    explicit ServerProcess(QDir baseDir, QObject *parent = 0);
    virtual void start();
};

#endif

