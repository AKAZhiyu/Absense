#include "pass.h"
#include "ui_pass.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
pass::pass(Person* p, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pass),
    p(p)
{
    ui->setupUi(this);
}

pass::~pass()
{
    delete ui;
}

void pass::on_cancelButton_clicked()
{
    this->close();
}


void pass::on_confirmButton_clicked()
{
    QString input_password = ui->originEdit->text();
    if (input_password != QString::fromStdString(p->getPasswd())) {
        QMessageBox::warning(this, "Reset", "密码错误");
    } else {
        if (ui->newEdit->text() != ui->confirmEdit->text()) {
            QMessageBox::warning(this, "Reset", "两次密码不一致");
        } else {
            std::string new_password = (ui->newEdit->text()).toStdString();

            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("localhost");
            db.setDatabaseName("schooldb");
            db.setUserName("root");
            db.setPassword("zzx20030628");
            if (!db.open()) {
                QMessageBox::warning(this, "Reset", "数据库连接失败");
                this->close();
            }

            QSqlQuery query;
            QString sqlStatement = "UPDATE " + QString::fromStdString(p->getTable())
                                   + " SET password = :new_password WHERE id = :student_id";

            query.prepare(sqlStatement);
            query.bindValue(":new_password", ui->newEdit->text());
            query.bindValue(":student_id", p->getId());

            if (!query.exec()) {
                QMessageBox::warning(this, "Reset", "数据库修改失败");
            } else {
                p->setPassword(new_password);
                QMessageBox::information(this, "Reset", "修改成功");
                this->close();
            }


        }
    }
}

