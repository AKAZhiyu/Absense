#ifndef LOGIN_FAILED_H
#define LOGIN_FAILED_H

#include <QWidget>

namespace Ui {
class Login_failed;
}

class Login_failed : public QWidget
{
    Q_OBJECT

public:
    explicit Login_failed(QWidget *parent = nullptr);
    ~Login_failed();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Login_failed *ui;
};

#endif // LOGIN_FAILED_H
