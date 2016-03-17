#include "score.h"

using namespace std;

Score::Score()
{
    nbErreur = 0;
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

void Score::log(QString nom_partition){
    QFile file("../music/log.txt");
    if (!file.open(QIODevice::Text | QIODevice::Append))
       return;

    QTextStream out(&file);
    out << "Nom de la partition : "<< nom_partition << endl;
    out << "Nombre d'erreur :     "<< nbErreur << endl;
    out << "---------------------------------" << endl;
}





