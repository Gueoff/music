#include "partition.h"
#include <iostream>
#include <QDebug>


using namespace std;


Partition::Partition()
{
    this->interval = 12;

    QGridLayout *layout = new QGridLayout;
    layout->setAlignment(Qt::AlignAbsolute);

    QPainter painter(this);
    painter.setBackgroundMode(Qt::OpaqueMode);
    painter.setPen(Qt::black);

    painter.drawLine(5,this->height()/8+interval,this->width()-5,this->height()/8+interval);
    painter.drawLine(5,this->height()/8+2*interval,this->width()-5,this->height()/8+2*interval);
    painter.drawLine(5,this->height()/8+3*interval,this->width()-5,this->height()/8+3*interval);
    painter.drawLine(5,this->height()/8+4*interval,this->width()-5,this->height()/8+4*interval);
    painter.drawLine(5,this->height()/8+5*interval,this->width()-5,this->height()/8+5*interval);

    layout->addWidget(this);
}



void Partition::setBrush(const QBrush &brush)
{
    this->brush = brush;
    update();
}

void Partition::paintEvent(QPaintEvent *)
{
    afficherPortee();

    for (unsigned int i = 0; i<this->liste_notes.size();++i){
            afficherNote(liste_notes.at(i),i+1);
        }
}


void Partition::afficherPortee(){

    int interval = 12;

    QGridLayout *layout = new QGridLayout;
    layout->setAlignment(Qt::AlignAbsolute);

    QPainter painter(this);
    painter.setBackgroundMode(Qt::OpaqueMode);
    painter.setPen(Qt::black);

    painter.drawLine(5,this->height()/8+interval,this->width()-5,this->height()/8+interval);
    painter.drawLine(5,this->height()/8+2*interval,this->width()-5,this->height()/8+2*interval);
    painter.drawLine(5,this->height()/8+3*interval,this->width()-5,this->height()/8+3*interval);
    painter.drawLine(5,this->height()/8+4*interval,this->width()-5,this->height()/8+4*interval);
    painter.drawLine(5,this->height()/8+5*interval,this->width()-5,this->height()/8+5*interval);

    layout->addWidget(this);



    for (unsigned int i = 0; i<this->liste_notes.size();++i){
            afficherNote(liste_notes.at(i),i+1);
        }
}

void Partition::afficherNote(Note* n,int pos){

    float centre = (this->height()/8)+(n->getPosition_note()*interval);

    float circonference =12;
    float taille = 2.20*circonference;
    float position = pos*35;
    QPainter painter(this);
    painter.setBackgroundMode(Qt::OpaqueMode);
    painter.setPen(Qt::black);

    painter.drawEllipse(position,centre,circonference,circonference);
    painter.drawLine(position+circonference,centre+(circonference/2),position+circonference,centre+(circonference/2)-taille);

}
