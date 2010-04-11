#include "mainwindow.h"
#include "sconnect.h"
#include <QMessageBox>
#include <QNetworkCookieJar>

MainWindow::MainWindow()
{
    sconnect(&webView, SIGNAL(loadFinished(bool)), this, SLOT(onLoadFinished(bool)));
    sconnect(&boxDelayer, SIGNAL(timeout()), this, SLOT(onBoxDelayerTimeout()));

    setCentralWidget(&webView);
    resize(800, 480);
    webView.page()->networkAccessManager()->setCookieJar(new QNetworkCookieJar());
    webView.load(QUrl("http://localhost:8080"));
    webView.show();
    setWindowTitle("Midgard runtime");
    boxDelayer.setSingleShot(true);

    setWindowIcon(QIcon(":/midgard2-icon.png"));
}

void MainWindow::onLoadFinished(bool success)
{
    if (! success && ! boxDelayer.isActive())
        boxDelayer.start(50);
}

void MainWindow::onBoxDelayerTimeout()
{
    qDebug() << "Failed to load" << webView.url().toString();
    QMessageBox msgBox(QMessageBox::Warning, "Load fail",
                       "Failed to load the requested resource.",
                       QMessageBox::Ok, this);
    msgBox.exec();
}
