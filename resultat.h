#ifndef RESULTAT_H
#define RESULTAT_H

#include <QWidget>
#include <vector>
#include <QPainter>
#include <QBrush>
#include <QWidget>
#include <QGridLayout>
#include "note.h"
#include <algorithm>
#include "score.h"

class Resultat : public QWidget
{
    Q_OBJECT
public:
    explicit Resultat(QWidget *parent = 0);
    void afficherRes();
    Resultat(std::vector<Note*> liste_clavier,std::vector<Note*> liste_parti);
    void afficherNoteFaute(Note* n, int pos);
    void afficherNoteJuste(Note* n, int pos);
    void paintEvent(QPaintEvent *);
    void setNote(std::vector<Note*> a,std::vector<Note*> b){this->liste_clavier = a; this->liste_parti = b;}
    std::vector<Note*> getListeClavier(){return this->liste_clavier;}
    void vider(){this->liste_clavier.clear(); this->liste_parti.clear();}

signals:

public slots:

private:
    Score sc;
    std::vector<Note*> liste_clavier;
    std::vector<Note*> liste_parti;
};

#endif // RESULTAT_H
