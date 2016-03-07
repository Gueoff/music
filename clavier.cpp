#include "clavier.h"

Clavier::Clavier()
{

}

void Clavier::afficherClavier(){
     //Premier octave
     Note a1(A,1,1);
     Note b1(B,1,1);
     Note c1(C,1,1);
     Note d1(D,1,1);
     Note e1(E,1,1);
     Note f1(F,1,1);
     Note g1(G,1,1);
     Touche *do1 = new Touche(&a1);
     Touche *re1 = new Touche(&b1);
     Touche *mi1 = new Touche(&c1);
     Touche *fa1 = new Touche(&d1);
     Touche *sol1 = new Touche(&e1);
     Touche *la1 = new Touche(&f1);
     Touche *si1 = new Touche(&g1);
     //Diez
     Note a11(A,2,1);
     Note b11(B,2,1);
     Note d11(D,2,1);
     Note e11(E,2,1);
     Note f11(F,2,1);
     Touche *do11 = new Touche(&a11);
     Touche *re11 = new Touche(&b11);
     Touche *fa11 = new Touche(&d11);
     Touche *sol11 = new Touche(&e11);
     Touche *la11 = new Touche(&f11);

     //Deuxieme octave
     Note a2(A,1,2);
     Note b2(B,1,2);
     Note c2(C,1,2);
     Note d2(D,1,2);
     Note e2(E,1,2);
     Note f2(F,1,2);
     Note g2(G,1,2);
     Touche *do2 = new Touche(&a2);
     Touche *re2 = new Touche(&b2);
     Touche *mi2 = new Touche(&c2);
     Touche *fa2 = new Touche(&d2);
     Touche *sol2 = new Touche(&e2);
     Touche *la2 = new Touche(&f2);
     Touche *si2 = new Touche(&g2);
     //Diez
     Note a22(A,2,2);
     Note b22(B,2,2);
     Note d22(D,2,2);
     Note e22(E,2,2);
     Note f22(F,2,2);
     Touche *do22 = new Touche(&a22);
     Touche *re22 = new Touche(&b22);
     Touche *fa22 = new Touche(&d22);
     Touche *sol22 = new Touche(&e22);
     Touche *la22 = new Touche(&f22);

      //Placement des touches
      QGridLayout *layoutBouton = new QGridLayout;
      layoutBouton->setMargin(100);
      layoutBouton->setSpacing(0);

      //Premier octave
       layoutBouton->addWidget(do1, 0, 0);
       layoutBouton->addWidget(do11, 0, 1);
       layoutBouton->addWidget(re1, 0, 2);
       layoutBouton->addWidget(re11, 0, 3);
       layoutBouton->addWidget(mi1, 0, 4);
       layoutBouton->addWidget(fa1, 0, 5);
       layoutBouton->addWidget(fa11, 0, 6);
       layoutBouton->addWidget(sol1, 0, 7);
       layoutBouton->addWidget(sol11, 0, 8);
       layoutBouton->addWidget(la1, 0, 9);
       layoutBouton->addWidget(la11, 0, 10);
       layoutBouton->addWidget(si1, 0, 11);
       //Deuxieme octave
       /*layoutBouton->addWidget(do2, 0, 7);
       layoutBouton->addWidget(do22, 0, 7);
       layoutBouton->addWidget(re2, 0, 8);
       layoutBouton->addWidget(re22, 0, 8);
       layoutBouton->addWidget(mi2, 0, 9);
       layoutBouton->addWidget(fa2, 0, 10);
       layoutBouton->addWidget(fa22, 0, 10);
       layoutBouton->addWidget(sol2, 0, 11);
       layoutBouton->addWidget(sol22, 0, 11);
       layoutBouton->addWidget(la2, 0, 12);
       layoutBouton->addWidget(la22, 0, 12);
       layoutBouton->addWidget(si2, 0, 13);
*/
       this->setLayout(layoutBouton);
}


void Clavier::paintEvent(QPaintEvent *)
{
    afficherClavier();

}
