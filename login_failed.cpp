#include "login_failed.h"
#include "ui_login_failed.h"

Login_failed::Login_failed(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login_failed)
{
    ui->setupUi(this);
}

Login_failed::~Login_failed()
{
    delete ui;
}

void Login_failed::on_pushButton_clicked()
{
    this->close();
}

