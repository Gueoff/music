#include "clavier.h"

Clavier::Clavier()
{
    //Premier octave
    Note a1(A,1,1);//DO
    Note b1(B,1,1);//RE
    Note c1(C,1,1);//MI
    Note d1(D,1,1);//FA
    Note e1(E,1,1);//SOL
    Note f1(F,1,1);//LA
    Note g1(G,1,1);//SI
    Touche *do1 = new Touche(&c1);
    Touche *re1 = new Touche(&d1);
    Touche *mi1 = new Touche(&e1);
    Touche *fa1 = new Touche(&f1);
    Touche *sol1 = new Touche(&g1);
    Touche *la1 = new Touche(&a1);
    Touche *si1 = new Touche(&b1);
    //Diez
    Note c11(C,2,1);
    Note d11(D,2,1);
    Note f11(F,2,1);
    Note g11(G,2,1);
    Note a11(A,2,1);
    Touche *do11 = new Touche(&c11);
    Touche *re11 = new Touche(&d11);
    Touche *fa11 = new Touche(&f11);
    Touche *sol11 = new Touche(&g11);
    Touche *la11 = new Touche(&a11);

    //Deuxieme octave
    Note a2(A,1,2);
    Note b2(B,1,2);
    Note c2(C,1,2);
    Note d2(D,1,2);
    Note e2(E,1,2);
    Note f2(F,1,2);
    Note g2(G,1,2);
    Touche *do2 = new Touche(&c2);
    Touche *re2 = new Touche(&d2);
    Touche *mi2 = new Touche(&e2);
    Touche *fa2 = new Touche(&f2);
    Touche *sol2 = new Touche(&g2);
    Touche *la2 = new Touche(&a2);
    Touche *si2 = new Touche(&b2);
    //Diez
    Note c22(C,2,2);
    Note d22(D,2,2);
    Note f22(F,2,2);
    Note g22(G,2,2);
    Note a22(A,2,2);
    Touche *do22 = new Touche(&c22);
    Touche *re22 = new Touche(&d22);
    Touche *fa22 = new Touche(&f22);
    Touche *sol22 = new Touche(&g22);
    Touche *la22 = new Touche(&a22);

     //Placement des touches
     QGridLayout *layoutBouton = new QGridLayout;
     //layoutBouton->setMargin(100);
     layoutBouton->setSpacing(0);
     layoutBouton->setAlignment(Qt::AlignAbsolute);

     //Premier octave
      layoutBouton->addWidget(do1, 0, 0, 1, 3);
      layoutBouton->addWidget(re1, 0, 3, 1, 3);
      layoutBouton->addWidget(mi1, 0, 6, 1, 3);
      layoutBouton->addWidget(fa1, 0, 9, 1, 3);
      layoutBouton->addWidget(sol1, 0, 12, 1, 3);
      layoutBouton->addWidget(la1, 0, 15, 1, 3);
      layoutBouton->addWidget(si1, 0, 18, 1, 3);
      //Diez
      layoutBouton->addWidget(do11, 0, 2, 1, 2);
      layoutBouton->addWidget(re11, 0, 5, 1, 2);
      layoutBouton->addWidget(fa11, 0, 11, 1, 2);
      layoutBouton->addWidget(sol11, 0, 14, 1, 2);
      layoutBouton->addWidget(la11, 0, 17, 1, 2);

      //Deuxieme octave
      layoutBouton->addWidget(do2, 0, 21, 1, 3);
      layoutBouton->addWidget(re2, 0, 24, 1, 3);
      layoutBouton->addWidget(mi2, 0, 27, 1, 3);
      layoutBouton->addWidget(fa2, 0, 30, 1, 3);
      layoutBouton->addWidget(sol2, 0, 33, 1, 3);
      layoutBouton->addWidget(la2, 0, 36, 1, 3);
      layoutBouton->addWidget(si2, 0, 39, 1, 3);
      //Diez
      layoutBouton->addWidget(do22, 0, 23, 1, 2);
      layoutBouton->addWidget(re22, 0, 26, 1, 2);
      layoutBouton->addWidget(fa22, 0, 32, 1, 2);
      layoutBouton->addWidget(sol22, 0, 35, 1, 2);
      layoutBouton->addWidget(la22, 0, 38, 1, 2);




      this->setLayout(layoutBouton);
}

void Clavier::afficherClavier(){

     //Premier octave
     Note a1(A,1,1);//DO
     Note b1(B,1,1);//RE
     Note c1(C,1,1);//MI
     Note d1(D,1,1);//FA
     Note e1(E,1,1);//SOL
     Note f1(F,1,1);//LA
     Note g1(G,1,1);//SI
     Touche *do1 = new Touche(&c1);
     Touche *re1 = new Touche(&d1);
     Touche *mi1 = new Touche(&e1);
     Touche *fa1 = new Touche(&f1);
     Touche *sol1 = new Touche(&g1);
     Touche *la1 = new Touche(&a1);
     Touche *si1 = new Touche(&b1);
     //Diez
     Note c11(C,2,1);
     Note d11(D,2,1);
     Note f11(F,2,1);
     Note g11(G,2,1);
     Note a11(A,2,1);
     Touche *do11 = new Touche(&c11);
     Touche *re11 = new Touche(&d11);
     Touche *fa11 = new Touche(&f11);
     Touche *sol11 = new Touche(&g11);
     Touche *la11 = new Touche(&a11);

     //Deuxieme octave
     Note a2(A,1,2);
     Note b2(B,1,2);
     Note c2(C,1,2);
     Note d2(D,1,2);
     Note e2(E,1,2);
     Note f2(F,1,2);
     Note g2(G,1,2);
     Touche *do2 = new Touche(&c2);
     Touche *re2 = new Touche(&d2);
     Touche *mi2 = new Touche(&e2);
     Touche *fa2 = new Touche(&f2);
     Touche *sol2 = new Touche(&g2);
     Touche *la2 = new Touche(&a2);
     Touche *si2 = new Touche(&b2);
     //Diez
     Note c22(C,2,2);
     Note d22(D,2,2);
     Note f22(F,2,2);
     Note g22(G,2,2);
     Note a22(A,2,2);
     Touche *do22 = new Touche(&c22);
     Touche *re22 = new Touche(&d22);
     Touche *fa22 = new Touche(&f22);
     Touche *sol22 = new Touche(&g22);
     Touche *la22 = new Touche(&a22);

      //Placement des touches
      QGridLayout *layoutBouton = new QGridLayout;
      //layoutBouton->setMargin(100);
      layoutBouton->setSpacing(0);

      layoutBouton->setAlignment(Qt::AlignAbsolute);

      //Premier octave
       layoutBouton->addWidget(do1, 0, 0, 1, 3);
       layoutBouton->addWidget(re1, 0, 3, 1, 3);
       layoutBouton->addWidget(mi1, 0, 6, 1, 3);
       layoutBouton->addWidget(fa1, 0, 9, 1, 3);
       layoutBouton->addWidget(sol1, 0, 12, 1, 3);
       layoutBouton->addWidget(la1, 0, 15, 1, 3);
       layoutBouton->addWidget(si1, 0, 18, 1, 3);
       //Diez
       layoutBouton->addWidget(do11, 0, 2, 1, 2);
       layoutBouton->addWidget(re11, 0, 5, 1, 2);
       layoutBouton->addWidget(fa11, 0, 11, 1, 2);
       layoutBouton->addWidget(sol11, 0, 14, 1, 2);
       layoutBouton->addWidget(la11, 0, 17, 1, 2);

       //Deuxieme octave
       layoutBouton->addWidget(do2, 0, 21, 1, 3);
       layoutBouton->addWidget(re2, 0, 24, 1, 3);
       layoutBouton->addWidget(mi2, 0, 27, 1, 3);
       layoutBouton->addWidget(fa2, 0, 30, 1, 3);
       layoutBouton->addWidget(sol2, 0, 33, 1, 3);
       layoutBouton->addWidget(la2, 0, 36, 1, 3);
       layoutBouton->addWidget(si2, 0, 39, 1, 3);
       //Diez
       layoutBouton->addWidget(do22, 0, 23, 1, 2);
       layoutBouton->addWidget(re22, 0, 26, 1, 2);
       layoutBouton->addWidget(fa22, 0, 32, 1, 2);
       layoutBouton->addWidget(sol22, 0, 35, 1, 2);
       layoutBouton->addWidget(la22, 0, 38, 1, 2);


       this->setLayout(layoutBouton);
}



void Clavier::paintEvent(QPaintEvent *)
{
    afficherClavier();

}
