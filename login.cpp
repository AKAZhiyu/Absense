#include "login.h"
#include "ui_login.h"
#include"logintips.h"
#include"login_failed.h"
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::validateLogin()
{

    if(ui->lineEdit_usrname->text() == "admin" && ui->lineEdit_passwd->text() == "admin") {
        LoginTips* l = new LoginTips();
        l->show();
        this->close();
    } else {
        Login_failed* l = new Login_failed();
        l->show();
    }

}

void Login::on_pushButton_exit_clicked()
{
    this->close();

}


void Login::on_pushButton_login_clicked()
{
    validateLogin();
}

