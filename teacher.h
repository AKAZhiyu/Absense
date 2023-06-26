#ifndef TEACHER_H
#define TEACHER_H

#include <QWidget>
#include"tea.h"
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableView>
#include <QSqlTableModel>
#include <QStandardItemModel>
namespace Ui {
class Teacher;
}

class Teacher : public QWidget
{
    Q_OBJECT

public:
    explicit Teacher(Tea* teacher, QWidget *parent = nullptr);
    ~Teacher();
signals:
    void notifyParent();

private slots:
    void on_exitButton_clicked();

private:
    Ui::Teacher *ui;
    Tea* teacher;
    QSqlDatabase db;
    QSqlTableModel* m;
};

#endif // TEACHER_H
