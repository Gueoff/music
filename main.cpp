#include "mainwindow.h"
#include <QApplication>
#include "partition.h"
#include "clavier.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    Partition partition;
    Clavier clavier;

    //partition.show();
    //clavier.show();
    //clavier.afficherClavier();
    clavier.show();


    return a.exec();
}
