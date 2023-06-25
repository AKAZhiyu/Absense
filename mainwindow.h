#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QString>
#include <QSqlDatabase>
#include <QSqlQuery>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pushButton_exit_clicked();

    void on_pushButton_login_clicked();

private:
    Ui::MainWindow *ui;
    void validateLogin_Student();

    QSqlDatabase db;
};
#endif // MAINWINDOW_H
