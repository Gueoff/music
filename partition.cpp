#include "partition.h"
#include <iostream>
#include <QDebug>
#include <QDir>

using namespace std;

/**
 * @brief Partition::Partition Constructeur d'une partition.
 */
Partition::Partition()
{
    this->interval = 12;
    this->setMinimumHeight(500);
}

/**
 * @brief Partition::paintEvent Appelle le dessin de partition.
 */
void Partition::paintEvent(QPaintEvent *)
{
    afficherPortee();
}


/**
 * @brief Partition::afficherPortee Dessine une partition dans le QWidget.
 * Affiche également les notes d'une partition s'il y en a.
 */
void Partition::afficherPortee(){



    QGridLayout *layout = new QGridLayout;
    layout->setAlignment(Qt::AlignAbsolute);

    QPainter painter(this);



    //painter.drawPixmap(100,this->height()/8+3*interval,10,10,pixmap2);
    //painter.setBackgroundMode(Qt::OpaqueMode);
    painter.setBackgroundMode(Qt::TransparentMode);
    painter.setPen(Qt::black);

    //Lignes horizontales
    painter.drawLine(80,this->height()/8+interval,this->width()-100,this->height()/8+interval);
    painter.drawLine(80,this->height()/8+2*interval,this->width()-100,this->height()/8+2*interval);
    painter.drawLine(80,this->height()/8+3*interval,this->width()-100,this->height()/8+3*interval);
    painter.drawLine(80,this->height()/8+4*interval,this->width()-100,this->height()/8+4*interval);
    painter.drawLine(80,this->height()/8+5*interval,this->width()-100,this->height()/8+5*interval);

    //Lignes verticales
    painter.setPen(QPen(Qt::black,2, Qt::SolidLine));
    //painter.drawLine(80,this->height()/8+interval+1,100,this->height()/8+5*interval-1);
    painter.drawLine(this->width()/4+50,this->height()/8+interval+1,this->width()/4+50,this->height()/8+5*interval-1);
    painter.drawLine(this->width()/2,this->height()/8+interval+1,this->width()/2,this->height()/8+5*interval-1);
    painter.drawLine(this->width()/2+this->width()/4-50,this->height()/8+interval+1,this->width()/2+this->width()/4-50,this->height()/8+5*interval-1);
    painter.drawLine(this->width()-100,this->height()/8+interval+1,this->width()-100,this->height()/8+5*interval-1);
    painter.drawLine(this->width()-105,this->height()/8+interval+1,this->width()-105,this->height()/8+5*interval-1);

    layout->addWidget(this);

    //Cle de sol
    QPixmap clef( "../music/image/clef_sol.png");
    painter.drawPixmap(80,this->height()/8+3,clef.scaled(35,80));

    painter.setFont(QFont("Segoe Print",20));
    painter.drawText(this->width()/2-50,this->height()/8-35 ,this->nom );


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

/**
 * @brief Partition::afficherNote affiche une note sur la partition.
 * @param n la note a afficher.
 * @param pos la position de la note sur la partition.
 * @param etat 1 si la note est celle à jouer, 2 sinon.
 */
void Partition::afficherNote(Note* n, int pos, int etat){

    float centre = (this->height()/8)+(n->getPosition_note()*interval);
    float circonference =12;
    float position = pos*45 + 98;
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
    if(n->getAlteration() == 1){
         QPixmap diese("../music/image/diese.png");
         painter.drawPixmap(position -20,centre-circonference/2,diese.scaled(10,25));

    }
}

/**
 * @brief Partition::avancer fait avancer le pointeur de la note à jouer.
 */
void Partition::avancer(){
    this->pointeur++;
}

