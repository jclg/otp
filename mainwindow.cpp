#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "displaykeydialog.h"
#include "helper.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    otp = new Otp();
    ui->setupUi(this);
    this->loadOtpKey("key.otp");
}

MainWindow::~MainWindow()
{
    delete otp;
    delete ui;
}

void MainWindow::loadOtpKey(QString filename, bool show_warning)
{
    QFile file(filename);
    QString filecontent;

    if (file.open(QFile::ReadOnly)) {
        QTextStream in(&file);
        filecontent = in.readAll();
        otp->setSecret(filecontent.toStdString());
        ui->statusBar->showMessage("File \""+filename+"\" successfully loaded as OTP key");
    }
    else {
        if (show_warning){
            QMessageBox::critical(this, tr("Can't open file"), tr("Cannot open and read this file. Please check permissions."), QMessageBox::Ok);
        }
        ui->statusBar->showMessage("Cannot open \""+filename+"\"");
    }
}

void MainWindow::on_encryptButton_clicked()
{
    QString cyphertext;
    QString plaintext;

    plaintext = ui->plainTextEdit->toPlainText();
    cyphertext = QString::fromStdString(Helper::base64Encode(otp->encrypt(plaintext.toStdString())));
    ui->plainTextEdit->setPlainText(cyphertext);
    ui->decryptButton->setEnabled(true);
    ui->encryptButton->setEnabled(false);
}

void MainWindow::on_decryptButton_clicked()
{
    QString cyphertext;
    QString plaintext;

    cyphertext = ui->plainTextEdit->toPlainText();
    plaintext = QString::fromStdString(otp->encrypt(Helper::base64Decode(cyphertext.toStdString())));
    ui->plainTextEdit->setPlainText(plaintext);
    ui->decryptButton->setEnabled(false);
    ui->encryptButton->setEnabled(true);
}

void MainWindow::on_actionLoadKey_triggered()
{
    QString filename;

    filename = QFileDialog::getOpenFileName(this, tr("Load a key..."), "", tr("Files (*.*)"));
    if (filename != "")
    {
        this->loadOtpKey(filename, true);
    }
}

void MainWindow::on_actionExit_triggered()
{
    qApp->exit();
}

void MainWindow::on_actionDisplayOTP_triggered()
{
    DisplayKeyDialog displaykeydialog;
    displaykeydialog.setContent(QString::fromStdString(otp->getSecret()));
    displaykeydialog.exec();
}

void MainWindow::on_actionAboutOTP_triggered()
{
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText("OTP\nA simple One-Time Pad tool in Qt\nMade by Jean-Charles Le Goff\n<jean-charles.le-goff@epitech.eu>");
    msgBox.exec();
}

