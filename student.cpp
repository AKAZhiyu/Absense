#include "student.h"
#include "ui_student.h"
#include <QMessageBox>
Student::Student(Stud* s, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Student),
    s(s)
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
    m = new QSqlTableModel;
    m->setTable("DetailedAbsences");

    ui->tableView->setModel(m);
    QString welcome = "你好，" + QString::fromStdString(s->getName()) + "同学";
    ui->label_welcome->setText(welcome);
    ui->label_name->setText(QString::fromStdString(s->getName()));
    ui->label_gender->setText(QString::fromStdString(s->getGender()));
    ui->label_major->setText(QString::fromStdString(s->getMajor()));
    ui->label_class->setText(QString::fromStdString(s->getClass()));
    ui->label_id->setText(QString::number(s->getId()));
    ui->label_age->setText(QString::number(s->getAge()));
}

Student::~Student()
{
    delete ui;
}


void Student::on_exitButton_clicked()
{
    this->close();
}


void Student::on_checkButton_clicked()
{
    m->select();
}

