#include "note.h"

Note::Note()
{
}

Note::Note(nom_note nom, int alteration, int octave){
    this->nom = nom;
    this->alteration = alteration;
    this->octave = octave;
}

void Note::afficherNote(){
    int centre = 40;
    int circonference =15;
    int taille = 2.20*circonference;

    QPainter painter(this);
    painter.setBackgroundMode(Qt::OpaqueMode);
    painter.setPen(Qt::black);

    painter.drawEllipse(centre,centre,circonference,circonference);
    painter.drawLine(centre+circonference,centre+(circonference/2),centre+circonference,centre+(circonference/2)-taille);

}
