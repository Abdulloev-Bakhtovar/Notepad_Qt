#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Notepad 2023");
    w.setWindowIcon(QIcon(":/icon/img/icon.png"));
    w.show();
    return a.exec();
}
