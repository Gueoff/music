#include "note.h"

Note::Note()
{
}

Note::Note(nom_note nom, int alteration, int octave){
    this->nom = nom;
    this->alteration = alteration;
    this->octave = octave;

    if(octave == 1){
            if(nom==C){
                this->position_note= 5.5;
            }
            else if(nom==D){
                this->position_note= 5;
            }
            else if(nom==E){
                this->position_note= 4.5;
            }
            else if(nom==F){
                this->position_note= 4;
            }
            else if(nom==G){
                this->position_note= 3.5;
            }
            else if(nom==A){
                this->position_note= 3;
            }
            else if(nom==B){
                this->position_note= 2.5;
            }

        }
        else{
            if(nom==C){
                this->position_note= 2;
            }
            else if(nom==D){
                this->position_note= 1.5;
            }
            else if(nom==E){
                this->position_note= 1;
            }
            else if(nom==F){
                this->position_note= 0.5;
            }
            else if(nom==G){
                this->position_note= 0;
            }
            else if(nom==A){
                this->position_note= -0.5;
            }
            else if(nom==B){
                this->position_note= -1;
            }
        }

}

bool Note::egale(Note *note){
    if(this->octave == note->getOctave() && this->alteration == note->getAlteration() && this->nom == note->getNom()){
        return true;
    }
    if((this->nom == B && this->alteration == 1  && this->octave == 1) && (note->nom == C && note->alteration == 0  && note->octave == 2))
        return true;

    if(this->octave == note->getOctave() && (this->nom == E && this->alteration == 1) && (note->nom == F && note->alteration == 0))
        return true;

    if( (note->nom == B && note->alteration == 1 && note->octave == 1) && (this->nom == C && this->alteration == 0 && this->octave == 2))
        return true;

    if(this->octave == note->getOctave() && (note->nom == E && note->alteration == 1) && (this->nom == F && this->alteration == 0))
        return true;

    return false;
}

