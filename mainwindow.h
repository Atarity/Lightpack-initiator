#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

#define CMD_PARAM " -device at90usb162 -hardware usb -operation erase f loadbuffer \"%1\" program verify start reset 0"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
public slots:
    void on_btnUploadFirmware_clicked();
    void processReadyReadStdout();
    void processStarted();
    void processFinished( int exitCode);
private slots:
    void on_btnRunTests_clicked();

    void on_btnStopCurrentOperation_clicked();

private:
    QString getFlipCommand();
    QString getTestCommand();
    void executeLoggedCommand(const QString &cmd);
private:
    Ui::MainWindow *ui;
    QProcess process;
};

#endif // MAINWINDOW_H
