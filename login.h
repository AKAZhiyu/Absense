#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();


private slots:
    void on_pushButton_exit_clicked();

    void on_pushButton_login_clicked();

private:
    Ui::Login *ui;
    void validateLogin();
};

#endif // LOGIN_H
