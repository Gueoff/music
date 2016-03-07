#ifndef TOUCHE_H
#define TOUCHE_H


#include <QPushButton>
#include <QPalette>
#include "note.h"


class Touche : public QPushButton
{
public:
    Touche();
    Touche(Note *note);

private:
    Note *note;
};

#endif // TOUCHE_H
