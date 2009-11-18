#include <QMainWindow>
#include <QWebView>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private:
    QWebView webView;

private slots:
    void onLoadFinished(bool success);
};
