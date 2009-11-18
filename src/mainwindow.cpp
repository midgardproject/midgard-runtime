#include "mainwindow.h"
#include "sconnect.h"
#include <QMessageBox>

MainWindow::MainWindow()
{
    sconnect(&webView, SIGNAL(loadFinished(bool)), this, SLOT(onLoadFinished(bool)));

    setCentralWidget(&webView);
    resize(800, 480);
    webView.load(QUrl("http://localhost:8000"));
    webView.show();
    setWindowTitle("Midgard runtime");
}

void MainWindow::onLoadFinished(bool success)
{
    if (! success) {
        qDebug() << "Failed to load" << webView.url().toString();
        QMessageBox msgBox(QMessageBox::Warning, "Load fail",
                           "Failed to load the requested resource.",
                           QMessageBox::Ok, this);
        msgBox.exec();
    }
}

