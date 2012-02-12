#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qprocess.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&process, SIGNAL(readyReadStandardOutput()), this, SLOT(processReadyReadStdout()));
    connect(&process, SIGNAL(started()), this, SLOT(processStarted()));
    connect(&process, SIGNAL(finished(int)), this, SLOT(processFinished(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::processReadyReadStdout()
{
    ui->textBrowser->append(QString(process.readAllStandardOutput()));
}

void MainWindow::processStarted()
{
    ui->btnRunTests->setEnabled(false);
    ui->btnUploadFirmware->setEnabled(false);
}

void MainWindow::processFinished(int exitCode)
{
    ui->btnRunTests->setEnabled(true);
    ui->btnUploadFirmware->setEnabled(true);
}

QString MainWindow::getFlipCommand()
{
    return ui->edtFlipPath->text().trimmed().append(" ").append(QString(CMD_PARAM).arg(ui->edtFirmwareImage->text().trimmed()));
}

QString MainWindow::getTestCommand()
{
    return ui->edtPythonPath->text().trimmed().append(" ").append(ui->edtTestScriptFile->text().trimmed());
}

void MainWindow::on_btnUploadFirmware_clicked()
{
    executeLoggedCommand(getFlipCommand());
}

void MainWindow::on_btnRunTests_clicked()
{
    executeLoggedCommand(getTestCommand());
}

void MainWindow::executeLoggedCommand(const QString &cmd)
{
    ui->textBrowser->append("----------------------------------------------------------------------------");
    ui->textBrowser->append(QString(">> ").append(cmd));
    process.start(cmd);
}

void MainWindow::on_btnStopCurrentOperation_clicked()
{
    if (process.state() != QProcess::NotRunning) process.kill();
}
