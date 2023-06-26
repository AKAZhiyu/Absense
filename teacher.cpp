#include "teacher.h"
#include "ui_teacher.h"

Teacher::Teacher(Tea* teacher, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Teacher),
    teacher(teacher)
{
    ui->setupUi(this);
}

Teacher::~Teacher()
{
    delete ui;
}

void Teacher::on_exitButton_clicked()
{
    this->close();
    emit notifyParent();
}

