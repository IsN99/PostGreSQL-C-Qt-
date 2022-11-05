#include "mainwindow.h"
#include <QApplication>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    if(!createConnection())
        return 1;
    if(!createTables())
        return 1;

    w.show();

    return a.exec();
}
