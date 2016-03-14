#include "window.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Window window;
    window.show();

    /*
    Parser* par = new Parser("partition1");
    Partition* p = new Partition(par->recupereNote());
    p->show();
*/
    return app.exec();
}



