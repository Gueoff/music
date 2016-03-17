#include "partition.h"
#include <iostream>
#include <QDebug>


using namespace std;


Partition::Partition()
{
    this->interval = 12;
    this->setMinimumHeight(500);
}

void Partition::paintEvent(QPaintEvent *)
{
    afficherPortee();

}


void Partition::afficherPortee(){

    QGridLayout *layout = new QGridLayout;
    layout->setAlignment(Qt::AlignAbsolute);

    QPainter painter(this);
    painter.setBackgroundMode(Qt::OpaqueMode);
    painter.setPen(Qt::black);

    //Lignes horizontales
    painter.drawLine(100,this->height()/8+interval,this->width()-100,this->height()/8+interval);
    painter.drawLine(100,this->height()/8+2*interval,this->width()-100,this->height()/8+2*interval);
    painter.drawLine(100,this->height()/8+3*interval,this->width()-100,this->height()/8+3*interval);
    painter.drawLine(100,this->height()/8+4*interval,this->width()-100,this->height()/8+4*interval);
    painter.drawLine(100,this->height()/8+5*interval,this->width()-100,this->height()/8+5*interval);

    //Lignes verticales
    painter.setPen(QPen(Qt::black,2, Qt::SolidLine));
    painter.drawLine(100,this->height()/8+interval+1,100,this->height()/8+5*interval-1);
    painter.drawLine(this->width()/4+50,this->height()/8+interval+1,this->width()/4+50,this->height()/8+5*interval-1);
    painter.drawLine(this->width()/2,this->height()/8+interval+1,this->width()/2,this->height()/8+5*interval-1);
    painter.drawLine(this->width()/2+this->width()/4-50,this->height()/8+interval+1,this->width()/2+this->width()/4-50,this->height()/8+5*interval-1);
    painter.drawLine(this->width()-100,this->height()/8+interval+1,this->width()-100,this->height()/8+5*interval-1);
    painter.drawLine(this->width()-105,this->height()/8+interval+1,this->width()-105,this->height()/8+5*interval-1);

    layout->addWidget(this);
    //Cle de sol
    QLabel  *label  = new QLabel;
    QPixmap *cle = new QPixmap("../music/sol.png");
    label->setPixmap(*cle);
    layout->addWidget(new QPushButton("hey"));




    unsigned int i;
    for (i = 0; i<this->liste_notes.size();++i){
        //Note actuelle
        if(this->pointeur == i){
            afficherNote(liste_notes.at(i),i+1, 2);
        }
        //Autre note
        else{
             afficherNote(liste_notes.at(i),i+1, 1);
        }
    }

}

void Partition::afficherNote(Note* n, int pos, int etat){

    float centre = (this->height()/8)+(n->getPosition_note()*interval);
    float circonference =12;
    float position = pos*45 + 90;
    QPainter painter(this);
    painter.setBackgroundMode(Qt::OpaqueMode);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);



        painter.drawEllipse(position,centre,circonference,circonference);
       // painter.drawLine(position+circonference,centre+(circonference/2),position+circonference,centre+(circonference/2)-taille);

    //Note en train d'etre jouée
    if(etat == 2){
        painter.setPen(Qt::green);
        painter.drawLine(position+circonference/2,this->height()/8-this->interval , position+circonference/2,this->height()/8+7*this->interval );

    }
    if((n->getNom() == C &&n->getOctave() == 1) ||( n->getNom() == A && n->getOctave() == 2)){
            painter.setPen(Qt::black);
            painter.drawLine(position-8,centre+(circonference/2),position+8+circonference,centre+(circonference/2));

        }
        if(n->getNom()==B && n->getOctave() == 2){
            painter.setPen(Qt::black);
            painter.drawLine(position-8,centre+(circonference),position+8+circonference,centre+(circonference));

        }

}

void Partition::avancer(){
    this->pointeur++;
}

