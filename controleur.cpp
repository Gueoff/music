#include "controleur.h"

Controleur::Controleur()
{
    QScrollArea *scroll = new QScrollArea;
    scroll->setWidget(this);
    scroll->setEnabled(true);

    this->layout = new QGridLayout;
    layout->setSpacing(0);
    layout->setMargin(10);
    layout->setAlignment(Qt::AlignTop);

    this->setStyleSheet ("QPushButton {"
                            "width:50%;"
                            "height:40%;"
                            "border-top : 1px solid blue;"
                            "border-bottom : 1px solid blue;"
                            "background-color: white;"
                            "padding:3%;"
                            "margin:0%;"
                            "text-align: top;"
                          "}"
                            "QPushButton:hover {"
                            "background-color:rgb(240,240,240);"
                            "}"
                         );

    this->changer = new QPushButton("Changer de partition");
    connect(changer, SIGNAL(clicked()), this, SLOT(changerPartition()) );

    layout->addWidget(changer, 0, 0);
    changerPartition();



    this->setLayout(layout);
}


void Controleur::genererPartition(int id){
    a->setVisible(false);
    b->setVisible(false);
    c->setVisible(false);
    d->setVisible(false);
    layout->removeWidget(a);
    layout->removeWidget(b);
    layout->removeWidget(c);
    layout->removeWidget(d);
    deplie = false;

    switch(id){
    case 1:
        this->parser = new Parser("partition1");
        parser->recupereNote();
        break;
    case 2:
        this->parser = new Parser("partition2");
        parser->recupereNote();
        break;
    }
}

void Controleur::changerPartition(){
    if(!deplie){
        this->a = new QPushButton("Partition 1");
        this->b = new QPushButton("Partition 2");
        this->c = new QPushButton("Partition 3");
        this->d = new QPushButton("Partition 4");

        QButtonGroup *groupe = new QButtonGroup;
        groupe->addButton( a, 1);
        groupe->addButton( b, 2);
        groupe->addButton( c, 3);
        groupe->addButton( d, 4);
        connect(groupe, SIGNAL(buttonClicked(int)), this, SLOT(genererPartition(int)));

        layout->addWidget(a, 1, 0);
        layout->addWidget(b, 2, 0);
        layout->addWidget(c, 3, 0);
        layout->addWidget(d, 4, 0);
        deplie = true;
    }
    else{
        a->setVisible(false);
        b->setVisible(false);
        c->setVisible(false);
        d->setVisible(false);
        layout->removeWidget(a);
        layout->removeWidget(b);
        layout->removeWidget(c);
        layout->removeWidget(d);
        deplie = false;
    }


    /*
    QFile fichier(":/partitions/premiere.txt");
    QString texte;
    if(fichier.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream flux(&fichier);

        while(!flux.atEnd()){
            std::cout << "dans while" << std::endl;
            texte = flux.readLine();
            QPushButton* a = new QPushButton();
            a->setText(texte);
            layout->addWidget(a, 0, 0);

        }

        fichier.close();
    }

    else{
    texte = "Impossible d'ouvrir le fichier !";
    QPushButton* a = new QPushButton();
    a->setText(texte);
    layout->addWidget(a, 1, 0);
    }
*/


}
