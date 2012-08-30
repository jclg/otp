#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "otp.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_decryptButton_clicked();

    void on_encryptButton_clicked();

    void on_actionExit_triggered();

    void on_actionDisplayOTP_triggered();

    void on_actionAboutOTP_triggered();

    void on_actionLoadKey_triggered();

private:
    Ui::MainWindow *ui;
    Otp *otp;
    void loadOtpKey(QString filename, bool show_warning = false);
};

#endif // MAINWINDOW_H
