#include "controleur.h"

/**
 * @brief Controleur::Controleur Constructeur du controleur.
 */
Controleur::Controleur()
{
    this->setMinimumWidth(200);
    this->setMaximumWidth(200);
    this->partition = new Partition();
    this->clavier = new Clavier();
    this->layout = new QGridLayout;
    layout->setMargin(0);
    QWidget *contenu = new QWidget();
    contenu->setLayout(layout);

    this->setStyleSheet ("QPushButton {"
                            "border-top : 1px solid black;"
                            "border-bottom : 0px solid black;"
                            "background-color: white;"
                            "padding:0%;"
                            "margin:0%;"
                            "text-align: top;"
                            "font-size: 15px;"
                          "}"
                            "QPushButton:hover {"
                            "background-color:rgb(240,240,240);"
                            "}"
                         );

    //Loader de partitions
    QStringList filtre;
    filtre << "*.xml";
    QDirIterator iterateur("../music/partitions/", filtre ,QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);

    QStringList partitions;
    int numero_partition = 1;
    QButtonGroup *groupe = new QButtonGroup;

    //On boucle sur les partitions
    while(iterateur.hasNext())
    {

        partitions << iterateur.next();
        //Création du bouton
        QString nom_partition = QString("Partition%1").arg(numero_partition);
        QPushButton *bouton = new QPushButton(nom_partition);
        bouton->setFixedSize(this->width()-20, 50);
        groupe->addButton( bouton, numero_partition);
        //Affichage du bouton
        layout->addWidget(bouton,numero_partition+1,0);
        numero_partition++;
    }

    this->nombre_partitions = numero_partition;
    connect(groupe, SIGNAL(buttonClicked(int)), this, SLOT(genererPartition(int)));

    this->setWidget(contenu);
}

/**
 * @brief Controleur::genererPartition Loade la partition selon l'id du bouton
 * @param id le numero du bouton sur lequel on a appuyé.
 */
void Controleur::genererPartition(int id){

    QString nom_partition = QString("partition%1").arg(id);
    this->parser = new Parser(nom_partition);

    clavier->vider();
    clavier->getResultat()->hide();
    clavier->getResultat()->vider();
    partition->setListeNotes(parser->recupereNote());
    partition->setNom(nom_partition);
    partition->setPointeur(0);
    partition->show();
    partition->repaint();
}


