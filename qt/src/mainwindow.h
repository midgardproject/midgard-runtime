#include <QMainWindow>
#include <QWebView>
#include <QTimer>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private:
    QWebView webView;
    QTimer boxDelayer;

private slots:
    void onLoadFinished(bool success);
    void onBoxDelayerTimeout();
};
