#ifndef SCONNECT_H
#define SCONNECT_H

#include <QObject>
#include <QDebug>

inline void sconnect(const QObject *from, const char* fromSignal,
                     const QObject *to, const char* toSignal, Qt::ConnectionType type = Qt::AutoConnection)
{
    if (!QObject::connect(from, fromSignal, to, toSignal, type))
        qFatal("    *****************\n"
               "Connect returned false, aborting, enable core dumping (ulimit -c unlimited), \n"
               "enable debug (qmake CONFIG+=debug), recompile, rerun and then use the\n"
               "core file with gdb's backtrace to see the location.\n"
               "    *****************\n");
}

#endif
