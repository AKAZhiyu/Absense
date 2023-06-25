#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "student.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("SchoolDB");
    db.setUserName("root");
    db.setPassword("zzx20030628");
    if (!db.open()) {
        // 错误处理
        QMessageBox::warning(this, "Login", "数据库连接错误！");
        this->close();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_exit_clicked()
{
    this->close();
}


void MainWindow::on_pushButton_login_clicked()
{
    validateLogin_Student();
}

void MainWindow::validateLogin_Student()
{
    QString input_name = ui->lineEdit_usrname->text();
    QString input_password = ui->lineEdit_passwd->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM students WHERE id = :id");
    query.bindValue(":id", input_name.toInt());

    if (query.exec()) {
        if (query.next()) {
            QString password = query.value(3).toString();
            if (password == input_password) {
                QMessageBox::information(this, "Login", "登录成功");
                unsigned id = query.value(0).toUInt();
                std::string name = query.value(1).toString().toStdString();
                std::string gender = query.value(2).toString().toStdString();
                std::string password = query.value(3).toString().toStdString();
                std::string major = query.value(4).toString().toStdString();
                std::string _class = query.value(5).toString().toStdString();
                unsigned age = query.value(6).toUInt();
                Stud *s = new Stud(id, name, gender, password, age, _class, major);
                this->hide();
                Student* student = new Student(s);
                student->show();
            } else {
                QMessageBox::warning(this, "Login", "密码错误");
            }
        } else {
            QMessageBox::warning(this, "Login", "用户不存在");
        }
    } else {
        QMessageBox::warning(this, "DbsError", "数据库查询失败");
    }

}

