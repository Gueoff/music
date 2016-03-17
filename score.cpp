#include "score.h"
#include <QDebug>

Score::Score()
{
    this->setVisible(false);
    nbErreur = 0;
}



void Score::afficherScore(std::vector<Note*> notes_partition, std::vector<Note*> notes_clavier){

    this->notes_partition = notes_partition;
    this->notes_clavier = notes_clavier;
    this->setMinimumHeight(200);
    this->setVisible(true);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(new QPushButton("Recommencer"));

    this->setLayout(layout);

}

std::vector<int> Score::calculErreur(std::vector<Note *> notes_partition, std::vector<Note *> notes_clavier){
    std::vector<int> res;
    for(unsigned int i=0;i<notes_clavier.size();++i ){
        if (!notes_partition.at(i)->egale(notes_clavier.at(i))){
           res.push_back(i);
        }
    }
    this->nbErreur = res.size();
    return res;
}

void Score::log(){
    QFile file("log/log.txt");
    if (!file.open(QIODevice::Text | QIODevice::Append))
       return;

    QTextStream out(&file);
    out << "Nombre d'erreur:"<<nbErreur<<endl;


}





