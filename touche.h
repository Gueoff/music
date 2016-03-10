#ifndef TOUCHE_H
#define TOUCHE_H

#include <QPushButton>
#include <QPalette>
#include<QSound>
#include "note.h"


class Touche : public QPushButton
{
private:
    Note *note;
public:
    Touche();
    Touche(Note *note);
    Note* getNote(){return note;}


};

#endif // TOUCHE_H
