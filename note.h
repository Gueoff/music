#ifndef NOTE_H
#define NOTE_H


enum nom_note{ A, B, C, D, E, F, G };

class Note
{
private:
    nom_note nom;
    int alteration;
    int octave;

public:
    Note();
    Note(nom_note nom, int alteration, int octave);
    void setNom(nom_note nom){this->nom = nom;}
    nom_note getNom(){return this->nom;}
    void setAlteration(int alteration){this->alteration = alteration;}
    int getAlteration(){return this->alteration;}
    void setOctave(int octave){this->octave = octave;}
    int getOctave(){return this->octave;}

};

#endif // NOTE_H
