#ifndef CLAVIER_H
#define CLAVIER_H

#include <QPainter>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QButtonGroup>
#include "touche.h"


class Clavier : public QWidget
{
    Q_OBJECT

public:
    Clavier();
    void paintEvent(QPaintEvent *);
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

public slots:
    void jouer(int);
};

#endif // CLAVIER_H
