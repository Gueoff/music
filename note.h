#ifndef NOTE_H
#define NOTE_H

#include <QPainter>
#include <QBrush>
#include <QWidget>

enum nom_note{ A, B, C, D, E, F, G };




class Note: public QWidget
{
    Q_OBJECT

private:
    nom_note nom;
    int alteration;
    int octave;

public:
    Note();
    Note(nom_note nom, int alteration, int octave);
    void afficherNote();
    void setNom(nom_note nom){this->nom = nom;}
    nom_note getNom(){return this->nom;}
    void setAlteration(int alteration){this->alteration = alteration;}
    int getAlteration(){return this->alteration;}
    void setOctave(int octave){this->octave = octave;}
    int getOctave(){return this->octave;}

};

#endif // NOTE_H
