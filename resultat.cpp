#include "resultat.h"
#include <QDebug>
using namespace std;

Resultat::Resultat(QWidget *parent) :
    QWidget(parent)
{
}

Resultat::Resultat(std::vector<Note *> liste_clavier, std::vector<Note *> liste_parti){
    this->liste_clavier = liste_clavier;
    this->liste_parti = liste_parti;
}



void Resultat::paintEvent(QPaintEvent *)
{
    if(liste_clavier.size() > 0){
        afficherRes();
    }


}


void Resultat::afficherRes(){
    std::vector<int> res = sc.calculErreur(liste_parti,liste_clavier);
    QGridLayout *layout = new QGridLayout;
    layout->setAlignment(Qt::AlignAbsolute);

    QPainter painter(this);
    painter.setBackgroundMode(Qt::OpaqueMode);
    painter.setPen(Qt::black);

    painter.drawLine(5,this->height()/8+12,this->width()-5,this->height()/8+12);
    painter.drawLine(5,this->height()/8+2*12,this->width()-5,this->height()/8+2*12);
    painter.drawLine(5,this->height()/8+3*12,this->width()-5,this->height()/8+3*12);
    painter.drawLine(5,this->height()/8+4*12,this->width()-5,this->height()/8+4*12);
    painter.drawLine(5,this->height()/8+5*12,this->width()-5,this->height()/8+5*12);
    painter.setPen(QPen(Qt::black,2, Qt::SolidLine));
    painter.drawLine(this->width()-5,this->height()/8+12+1,this->width()-5,this->height()/8+5*12-1);
    painter.drawLine(this->width()-10,this->height()/8+12+1,this->width()-10,this->height()/8+5*12-1);
    layout->addWidget(this);

    for(unsigned j=0;j<res.size();++j){
         qDebug() << res.at(j);
    }

    unsigned int i;
    for (i = 0; i<liste_clavier.size();++i){

        if(std::find(res.begin(), res.end(), i) != res.end()) {

            afficherNoteFaute(liste_clavier.at(i),i+1);
        } else {
            qDebug() << "test2";
            afficherNoteJuste(liste_clavier.at(i),i+1);
        }

    }


}

void Resultat::afficherNoteFaute(Note* n, int pos){

    float centre = (this->height()/8)+(n->getPosition_note()*12);
    float circonference =12;
    //float taille = 2.20*circonference;
    float position = pos*35;
    QPainter painter(this);
    painter.setBackgroundMode(Qt::OpaqueMode);
    painter.setPen(Qt::red);
    painter.setBrush(Qt::red);



        painter.drawEllipse(position,centre,circonference,circonference);
       // painter.drawLine(position+circonference,centre+(circonference/2),position+circonference,centre+(circonference/2)-taille);



    if((n->getNom() == C &&n->getOctave() == 1) ||( n->getNom() == A && n->getOctave() == 2)){
            painter.setPen(Qt::black);
            painter.drawLine(position-8,centre+(circonference/2),position+8+circonference,centre+(circonference/2));

        }
        if(n->getNom()==B && n->getOctave() == 2){
            painter.setPen(Qt::black);
            painter.drawLine(position-8,centre+(circonference),position+8+circonference,centre+(circonference));

        }
        painter.setPen(QPen(Qt::black,2, Qt::SolidLine));
        if (pos % 4 ==0){
            painter.drawLine(position+25,this->height()/8+12+1,position+25,this->height()/8+5*12-1);
        }

}

void Resultat::afficherNoteJuste(Note* n, int pos){

    float centre = (this->height()/8)+(n->getPosition_note()*12);
    float circonference =12;
    //float taille = 2.20*circonference;
    float position = pos*35;
    QPainter painter(this);
    painter.setBackgroundMode(Qt::OpaqueMode);
    painter.setPen(Qt::darkGreen);
    painter.setBrush(Qt::darkGreen);



        painter.drawEllipse(position,centre,circonference,circonference);
       // painter.drawLine(position+circonference,centre+(circonference/2),position+circonference,centre+(circonference/2)-taille);


    if((n->getNom() == C &&n->getOctave() == 1) ||( n->getNom() == A && n->getOctave() == 2)){
            painter.setPen(Qt::black);
            painter.drawLine(position-8,centre+(circonference/2),position+8+circonference,centre+(circonference/2));

        }
        if(n->getNom()==B && n->getOctave() == 2){
            painter.setPen(Qt::black);
            painter.drawLine(position-8,centre+(circonference),position+8+circonference,centre+(circonference));

        }
        painter.setPen(QPen(Qt::black,2, Qt::SolidLine));
        if (pos % 4 ==0){
            painter.drawLine(position+25,this->height()/8+12+1,position+25,this->height()/8+5*12-1);
        }

}

