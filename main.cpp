#include "mainwindow.h"
#include <QApplication>
#include "partition.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    Partition partition;

    partition.show();


    return a.exec();
}
