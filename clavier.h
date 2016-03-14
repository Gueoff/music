#ifndef CLAVIER_H
#define CLAVIER_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QButtonGroup>
#include "touche.h"
#include "partition.h"


class Clavier : public QWidget
{
    Q_OBJECT

private:
    //Premier octave
    Touche *do1;
    Touche *re1;
    Touche *mi1;
    Touche *fa1;
    Touche *sol1;
    Touche *la1;
    Touche *si1;
    //Diez
    Touche *do11;
    Touche *re11;
    Touche *fa11;
    Touche *sol11;
    Touche *la11;
    //Deuxieme octave
    Touche *do2;
    Touche *re2;
    Touche *mi2;
    Touche *fa2;
    Touche *sol2;
    Touche *la2;
    Touche *si2;
    //Diez
    Touche *do22;
    Touche *re22;
    Touche *fa22;
    Touche *sol22;
    Touche *la22;

    Note *selected;
    Partition *partition;

public:
    Clavier();
    void paintEvent(QPaintEvent *);
    void setSelected(Note* note){this->selected = note;}
    Partition* getPartition(){return this->partition;}
    void setPartition(Partition* p){this->partition = p;}

public slots:
    void jouer(int);
};

#endif // CLAVIER_H
