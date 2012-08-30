#ifndef DISPLAYKEYDIALOG_H
#define DISPLAYKEYDIALOG_H

#include <QDialog>

namespace Ui {
class DisplayKeyDialog;
}

class DisplayKeyDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit DisplayKeyDialog(QWidget *parent = 0);
    ~DisplayKeyDialog();
    void setContent(QString content);
    
private slots:
    void on_okButton_clicked();

private:
    Ui::DisplayKeyDialog *ui;
};

#endif // DISPLAYKeyDialog_H
