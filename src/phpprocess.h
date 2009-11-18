#include <QObject>
#include <QProcess>
#include <QDir>
#include "runtimeprocess.h"

#ifndef PHPPROCESS_H
#define PHPPROCESS_H

class PhpProcess : public RuntimeProcess
{
    Q_OBJECT

public:
    explicit PhpProcess(QDir baseDir, QObject *parent = 0);
    void start();
};

#endif

