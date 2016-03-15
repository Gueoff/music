#include "window.h"


Window::Window()
{
    this->resize(1200,500);
    this->setWindowTitle("Apprentissage du solfege");
    this->setFixedSize(this->size());


    this->controleur = new Controleur();
    this->partition = controleur->getPartition();
    this->clavier = controleur->getClavier();
    clavier->setPartition(this->partition);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(controleur, 0, 0, 2, 1);
    layout->addWidget(partition, 0, 1, 1, 4);
    layout->addWidget(clavier, 1, 1, 1, 4);
    //layout->addWidget(score, 1, 1, 1, 4);




    this->setLayout(layout);
}
