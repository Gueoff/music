#include "score.h"
#include <QDebug>

Score::Score()
{
    this->setVisible(false);
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

void Score::log(){
    QFile file("log.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
       return;

    QTextStream out(&file);
    out << "Le Texte écrit dans le out.txt";

}



