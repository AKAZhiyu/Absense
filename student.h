#ifndef STUDENT_H
#define STUDENT_H
#include <QWidget>
#include "stud.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableView>
#include <QSqlTableModel>
#include <QStandardItemModel>
namespace Ui {
class Student;
}

class Student : public QWidget
{
    Q_OBJECT

public:
    explicit Student(Stud* s, QWidget *parent = nullptr);
    ~Student();

private slots:

    void on_exitButton_clicked();

    void on_checkButton_clicked();

private:
    Ui::Student *ui;
    Stud* s;
    QSqlDatabase db;
    QSqlTableModel* m;
};

#endif // STUDENT_H
