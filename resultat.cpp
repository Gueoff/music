#include "resultat.h"

using namespace std;

/**
 * @brief Resultat::Resultat Constructeur par défaut
 * @param parent
 */
Resultat::Resultat(QWidget *parent) :
    QWidget(parent)
{
    this->setMinimumHeight(500);
}

/**
 * @brief Resultat::Resultat Constructeur du résultat.
 * @param liste_clavier la liste de notes jouées au clavier par l'utilisateur.
 * @param liste_parti la liste de notes affichées sur la partition.
 */
Resultat::Resultat(std::vector<Note *> liste_clavier, std::vector<Note *> liste_parti){
    this->liste_clavier = liste_clavier;
    this->liste_parti = liste_parti;
    this->setMinimumHeight(500);
}


/**
 * @brief Resultat::paintEvent
 */
void Resultat::paintEvent(QPaintEvent *)
{
    if(liste_clavier.size() > 0){
        afficherRes();
    }
}

/**
 * @brief Resultat::afficherRes Affiche les résultats d'un morceau.
 * Affiche une partition avec le resultat.
 */
void Resultat::afficherRes(){
    std::vector<int> res = sc.calculErreur(liste_parti,liste_clavier);
    QGridLayout *layout = new QGridLayout;
    layout->setAlignment(Qt::AlignAbsolute);

    QPainter painter(this);
    painter.setBackgroundMode(Qt::OpaqueMode);
    painter.setPen(Qt::black);

    //Lignes horizontales
    painter.drawLine(100,this->height()/8+12,this->width()-100,this->height()/8+12);
    painter.drawLine(100,this->height()/8+2*12,this->width()-100,this->height()/8+2*12);
    painter.drawLine(100,this->height()/8+3*12,this->width()-100,this->height()/8+3*12);
    painter.drawLine(100,this->height()/8+4*12,this->width()-100,this->height()/8+4*12);
    painter.drawLine(100,this->height()/8+5*12,this->width()-100,this->height()/8+5*12);

    //Lignes verticales
    painter.setPen(QPen(Qt::black,2, Qt::SolidLine));
    painter.drawLine(100,this->height()/8+12+1,100,this->height()/8+5*12-1);
    painter.drawLine(this->width()/4+50,this->height()/8+12+1,this->width()/4+50,this->height()/8+5*12-1);
    painter.drawLine(this->width()/2,this->height()/8+12+1,this->width()/2,this->height()/8+5*12-1);
    painter.drawLine(this->width()/2+this->width()/4-50,this->height()/8+12+1,this->width()/2+this->width()/4-50,this->height()/8+5*12-1);
    painter.drawLine(this->width()-100,this->height()/8+12+1,this->width()-100,this->height()/8+5*12-1);
    painter.drawLine(this->width()-105,this->height()/8+12+1,this->width()-105,this->height()/8+5*12-1);

    layout->addWidget(this);

    unsigned int i;
    for (i = 0; i<liste_clavier.size();++i){

        if(std::find(res.begin(), res.end(), i) != res.end()) {
            afficherNoteFaute(liste_clavier.at(i),i+1);
        } else {
            afficherNoteJuste(liste_clavier.at(i),i+1);
        }
    }

    Score *score = new Score();
    score->calculErreur(this->liste_parti, this->liste_clavier);
    score->log(this->nom);
}

/**
 * @brief Resultat::afficherNoteFaute Dessine une note male jouée.
 * @param n la note à afficher.
 * @param pos la position de la note sur la partition.
 */
void Resultat::afficherNoteFaute(Note* n, int pos){

    float centre = (this->height()/8)+(n->getPosition_note()*12);
    float circonference =12;
    float position = pos*45 + 98;
    QPainter painter(this);
    painter.setBackgroundMode(Qt::OpaqueMode);
    painter.setPen(Qt::red);
    painter.setBrush(Qt::red);

    painter.drawEllipse(position,centre,circonference,circonference);

    if((n->getNom() == C &&n->getOctave() == 1) ||( n->getNom() == A && n->getOctave() == 2)){
        painter.setPen(Qt::black);
        painter.drawLine(position-8,centre+(circonference/2),position+8+circonference,centre+(circonference/2));
    }
    if(n->getNom()==B && n->getOctave() == 2){
        painter.setPen(Qt::black);
        painter.drawLine(position-8,centre+(circonference),position+8+circonference,centre+(circonference));
    }
}

/**
 * @brief Resultat::afficherNoteFaute Dessine une note bien jouée.
 * @param n la note à afficher.
 * @param pos la position de la note sur la partition.
 */
void Resultat::afficherNoteJuste(Note* n, int pos){

    float centre = (this->height()/8)+(n->getPosition_note()*12);
    float circonference =12;
    float position = pos*45 + 98;
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
}

