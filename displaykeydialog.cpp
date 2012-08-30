#include "displaykeydialog.h"
#include "ui_displaykeydialog.h"

DisplayKeyDialog::DisplayKeyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplayKeyDialog)
{
    ui->setupUi(this);
}

DisplayKeyDialog::~DisplayKeyDialog()
{
    delete ui;
}

void DisplayKeyDialog::on_okButton_clicked()
{
    this->close();
}

void DisplayKeyDialog::setContent(QString content)
{
    ui->otpDisplayText->setPlainText(content);
    if (content == "")
    {
        ui->label->setText("Your key is empty! Please load one using the menu (File -> Load a key...).");
    }
}
