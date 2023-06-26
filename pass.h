#ifndef PASS_H
#define PASS_H
#include"person.h"
#include <QWidget>

namespace Ui {
class pass;
}

class pass : public QWidget
{
    Q_OBJECT

public:
    explicit pass(Person* p, QWidget *parent = nullptr);
    ~pass();

private slots:
    void on_cancelButton_clicked();

    void on_confirmButton_clicked();

private:
    Ui::pass *ui;
    Person* p;
};

#endif // PASS_H
