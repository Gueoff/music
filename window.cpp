#include "window.h"




Window::Window()
{
    Clavier *clavier = new Clavier();
    Partition *partition = new Partition();

    QGridLayout *layoutBouton = new QGridLayout;
    layoutBouton->addWidget(partition, 0, 0);
    layoutBouton->addWidget(clavier, 1, 0);
    this->setLayout(layoutBouton);
}
