#ifndef PARTITION_H
#define PARTITION_H

#include <QPainter>
#include <QBrush>
#include <QWidget>
#include <QGridLayout>
#include <vector>
#include "note.h"
#include "score.h"


class Partition : public QWidget
{

    Q_OBJECT

private:
     std::vector<Note*> liste_notes;
     int interval;
     int pointeur;
     Score *score;
public:
     Partition();
     void paintEvent(QPaintEvent *);
     void afficherPortee();
     void afficherNote(Note*, int, int);
     void setListeNotes(std::vector<Note*> liste_notes){this->liste_notes = liste_notes;}
     std::vector<Note*> getListeNotes(){ return this->liste_notes;}
     void setPointeur(int pointeur){this->pointeur = pointeur;}
     int getPointeur(){return this->pointeur;}
     void setScore(Score *score){this->score = score;}
     Score* getScore(){return this->score;}
     void avancer();
     void afficherScores();

};

#endif // Partition_H
