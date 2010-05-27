#include <QObject>
#include <QApplication>
#include <QDebug>
#include <QDir>
#include <QWidget>
#include "mainwindow.h"
#include "runtime.h"

#ifndef MAIN_H
#define MAIN_H

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QStringList args = app.arguments();

    if (args.size() < 2) {
        qDebug() << "You need to provide runtime directory!";
        return 128;
    }

    QDir runtimeDirectory(args.at(1));
    if (runtimeDirectory.exists() == false) {
        qDebug() << "The directory doesn't exists!";
        return 128;
    }

    qDebug() << "Starting midgard runtime with project" << runtimeDirectory.absolutePath();
    Runtime runtime(runtimeDirectory);

    runtime.start();

    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}

#endif
