#include <QObject>
#include <QProcess>
#include <QDir>

#ifndef RUNTIMEPROCESS_H
#define RUNTIMEPROCESS_H

class RuntimeProcess : public QProcess
{
    Q_OBJECT

protected:
    QDir baseDir;

public:
    explicit RuntimeProcess(QDir baseDir, QObject *parent = 0);
    virtual void start() = 0;
};

#endif

