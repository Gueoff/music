#include "controleur.h"

Controleur::Controleur()
{
    this->bouton = new QPushButton("Changer de partition");
    connect(bouton, SIGNAL(clicked()), this, SLOT(genererPartition()) );


    QGridLayout *layout = new QGridLayout;
    layout->addWidget(bouton, 0, 0, 1, 3);
    this->setLayout(layout);
}


void Controleur::genererPartition(){
    bouton->setText("Ugo le trimar");
}
