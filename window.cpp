#include "window.h"

Window::Window()
{
    this->resize(1200,500);
    this->setWindowTitle("Apprentissage du solfege");
    this->setFixedSize(this->size());

    this->setStyleSheet( "QWidget{"
                            "background-color: white;"
                         "}");


    this->resultat = new Resultat();
    this->controleur = new Controleur();
    this->partition = controleur->getPartition();
    this->clavier = controleur->getClavier();

    this->clavier->setResultat(this->resultat);
    this->clavier->setPartition(this->partition);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(controleur, 0, 0, 2, 1);
    layout->addWidget(partition, 0, 1, 1, 4);
    layout->addWidget(clavier, 1, 1, 1, 4);
    layout->addWidget(resultat, 0, 1, 1, 4);


    this->setLayout(layout);
}
