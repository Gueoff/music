#include "window.h"


Window::Window()
{
    Clavier *clavier = new Clavier();
    Partition *partition = new Partition();
    Controleur *controleur = new Controleur();

    QGridLayout *layoutBouton = new QGridLayout;
    layoutBouton->addWidget(partition, 0, 0);
    layoutBouton->addWidget(clavier, 1, 0);
    layoutBouton->addWidget(controleur, 1, 1);
    this->setLayout(layoutBouton);
}
