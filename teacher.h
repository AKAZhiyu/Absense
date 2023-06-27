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

    void on_pushButton_pass_clicked();

    void on_searchButton_clicked();

    void on_searchBox_currentIndexChanged(int index);

    void on_addStudentButton_clicked();

    void on_AbsenseButton_clicked();

private:
    Ui::Teacher *ui;
    Tea* teacher;
    QSqlDatabase db;
    QSqlTableModel* m;
    QSqlQueryModel *model;
    void printMyCourse();
    void printAllCourse();
    void printAllStudent();
    void printAllAbsense();
    void printAllMyStudent();
    void printAllMyStudentAbsence();

    void searchCourseByName(QString name);
    void searchStudentByName(const QString& name);

    void searchCourseById(const QString& id);
    void searchStudentById(const QString& id);

    void searchAbsenceById(const QString& id);
    void searchAbsenceByName(const QString& name);

    bool studentIdIsDuplicate(const QString &id);

    bool validateCanBeNumber(const QString& id);
};

#endif // TEACHER_H
