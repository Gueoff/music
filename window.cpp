#include "window.h"


Window::Window()
{
    this->clavier = new Clavier();
    this->partition = new Partition();
    this->controleur = new Controleur();

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(controleur, 0, 0, 2, 1);
    layout->addWidget(partition, 0, 1, 1, 4);
    layout->addWidget(clavier, 1, 1, 1, 4);


    this->setLayout(layout);
}
