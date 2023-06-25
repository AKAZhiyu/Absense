#include "mainwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow l;
    l.show();

    return a.exec();
}
