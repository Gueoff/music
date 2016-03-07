#include "note.h"

Note::Note()
{
}

Note::Note(nom_note nom, int alteration, int octave){
    this->nom = nom;
    this->alteration = alteration;
    this->octave = octave;
}

