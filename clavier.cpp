#include "clavier.h"
#include <QDebug>

Clavier::Clavier()
{

    this->setMinimumHeight(400);
    //Création des touches
    //Premier octave
    Note a1(A,0,1);//LA
    Note b1(B,0,1);//SI
    Note c1(C,0,1);//DO
    Note d1(D,0,1);//RE
    Note e1(E,0,1);//MI
    Note f1(F,0,1);//FA
    Note g1(G,0,1);//SOL
    this->do1 = new Touche(&c1);
    this->re1 = new Touche(&d1);
    this->mi1 = new Touche(&e1);
    this->fa1 = new Touche(&f1);
    this->sol1 = new Touche(&g1);
    this->la1 = new Touche(&a1);
    this->si1 = new Touche(&b1);
    //Diez
    Note c11(C,1,1);
    Note d11(D,1,1);
    Note f11(F,1,1);
    Note g11(G,1,1);
    Note a11(A,1,1);
    this->do11 = new Touche(&c11);
    this->re11 = new Touche(&d11);
    this->fa11 = new Touche(&f11);
    this->sol11 = new Touche(&g11);
    this->la11 = new Touche(&a11);

    //Deuxieme octave
    Note a2(A,0,2);
    Note b2(B,0,2);
    Note c2(C,0,2);
    Note d2(D,0,2);
    Note e2(E,0,2);
    Note f2(F,0,2);
    Note g2(G,0,2);
    this->do2 = new Touche(&c2);
    this->re2 = new Touche(&d2);
    this->mi2 = new Touche(&e2);
    this->fa2 = new Touche(&f2);
    this->sol2 = new Touche(&g2);
    this->la2 = new Touche(&a2);
    this->si2 = new Touche(&b2);
    //Diez
    Note c22(C,1,2);
    Note d22(D,1,2);
    Note f22(F,1,2);
    Note g22(G,1,2);
    Note a22(A,1,2);
    this->do22 = new Touche(&c22);
    this->re22 = new Touche(&d22);
    this->fa22 = new Touche(&f22);
    this->sol22 = new Touche(&g22);
    this->la22 = new Touche(&a22);





    //Action des touches trié par ordre de gauche à droite sur le clavier
    //Premier octave
    QButtonGroup *groupe = new QButtonGroup;
    groupe->addButton( this->do1, 1);
    groupe->addButton( this->re1, 3);
    groupe->addButton( this->mi1, 5);
    groupe->addButton( this->fa1, 6);
    groupe->addButton( this->sol1, 8);
    groupe->addButton( this->la1, 10);
    groupe->addButton( this->si1, 12);
    //Diez
    groupe->addButton( this->do11, 2);
    groupe->addButton( this->re11, 4);
    groupe->addButton( this->fa11, 7);
    groupe->addButton( this->sol11, 9);
    groupe->addButton( this->la11, 11);
    //Deuxieme octave
    groupe->addButton( this->do2, 13);
    groupe->addButton( this->re2, 15);
    groupe->addButton( this->mi2, 17);
    groupe->addButton( this->fa2, 18);
    groupe->addButton( this->sol2, 20);
    groupe->addButton( this->la2, 22);
    groupe->addButton( this->si2, 24);
    //Diez
    groupe->addButton( this->do22, 14);
    groupe->addButton( this->re22, 16);
    groupe->addButton( this->fa22, 19);
    groupe->addButton( this->sol22, 21);
    groupe->addButton( this->la22, 23);

    connect(groupe, SIGNAL(buttonClicked(int)), this, SLOT(jouer(int)));

    //Placement des touches
    QGridLayout *layoutBouton = new QGridLayout;
    layoutBouton->setMargin(60);
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

}

/*!
 * \brief Clavier::jouer joue un son de piano mélodieux
 * \param id l'id de la touche pressée
 * Les id sont triés de la gauche vers la droite selon le clavier, DO=1, DO#=2, RE=3...
 */

void Clavier::jouer(int id){
    switch(id){
    case 1:
        QSound::play(":/sons/Do1.wav");
        this->setSelected(new Note(C,0,1));
        break;
    case 2:
        QSound::play(":/sons/Dod1.wav");
        this->setSelected(new Note(C,1,1));
        break;
    case 3:
        QSound::play(":/sons/Re1.wav");
        this->setSelected(new Note(D,0,1));
        break;
    case 4:
        QSound::play(":/sons/Red1.wav");
        this->setSelected(new Note(D,1,1));
        break;
    case 5:
        QSound::play(":/sons/Mi1.wav");
        this->setSelected(new Note(E,0,1));
        break;
    case 6:
        QSound::play(":/sons/Fa1.wav");
        this->setSelected(new Note(F,0,1));
        break;
    case 7:
        QSound::play(":/sons/Fad1.wav");
        this->setSelected(new Note(F,1,1));
        break;
    case 8:
        QSound::play(":/sons/Sol1.wav");
        this->setSelected(new Note(G,0,1));
        break;
    case 9:
        QSound::play(":/sons/Sold1.wav");
        this->setSelected(new Note(G,1,1));
        break;
    case 10:
        QSound::play(":/sons/La1.wav");
        this->setSelected(new Note(A,0,1));
        break;
    case 11:
        QSound::play(":/sons/Lad1.wav");
        this->setSelected(new Note(A,1,1));
        break;
    case 12:
        QSound::play(":/sons/Si1.wav");
        this->setSelected(new Note(B,0,1));
        break;
    case 13:
        QSound::play(":/sons/Do2.wav");
        this->setSelected(new Note(C,0,2));
        break;
    case 14:
        QSound::play(":/sons/Dod2.wav");
        this->setSelected(new Note(C,1,2));
        break;
    case 15:
        QSound::play(":/sons/Re2.wav");
        this->setSelected(new Note(D,0,2));
        break;
    case 16:
        QSound::play(":/sons/Red2.wav");
        this->setSelected(new Note(D,1,2));
        break;
    case 17:
        QSound::play(":/sons/Mi2.wav");
        this->setSelected(new Note(E,0,2));
        break;
    case 18:
        QSound::play(":/sons/Fa2.wav");
        this->setSelected(new Note(F,0,2));
        break;
    case 19:
        QSound::play(":/sons/Fad2.wav");
        this->setSelected(new Note(F,1,2));
        break;
    case 20:
        QSound::play(":/sons/Sol2.wav");
        this->setSelected(new Note(G,0,2));
        break;
    case 21:
        QSound::play(":/sons/Sold2.wav");
        this->setSelected(new Note(G,1,2));
        break;
    case 22:
        QSound::play(":/sons/La2.wav");
        this->setSelected(new Note(A,0,2));
        break;
    case 23:
        QSound::play(":/sons/Lad2.wav");
        this->setSelected(new Note(A,1,2));
        break;
    case 24:
        QSound::play(":/sons/Si2.wav");
        this->setSelected(new Note(B,0,2));
        break;

    }


    this->notes_joues.push_back(selected);
    this->getPartition()->avancer();

    if(this->getPartition()->getPointeur() == this->getPartition()->getListeNotes().size()){
        this->getPartition()->setPointeur(0);
        qDebug() << "arret";
    }

    this->getPartition()->afficherPortee();
    this->getPartition()->repaint();
}
