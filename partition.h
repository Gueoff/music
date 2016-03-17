#ifndef PARTITION_H
#define PARTITION_H

#include <QPainter>
#include <QBrush>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <vector>

#include <QString>
#include <string.h>

#include "note.h"


class Partition : public QWidget
{

    Q_OBJECT

private:
     std::vector<Note*> liste_notes;
     int interval;
     int pointeur;
     QString nom;
public:
     Partition();
     void paintEvent(QPaintEvent *);
     void afficherPortee();
     void afficherNote(Note*, int, int);
     void setListeNotes(std::vector<Note*> liste_notes){this->liste_notes = liste_notes;}
     std::vector<Note*> getListeNotes(){ return this->liste_notes;}
     void setPointeur(int pointeur){this->pointeur = pointeur;}
     int getPointeur(){return this->pointeur;}
     void setNom(QString nom){this->nom = nom;}
     QString getNom(){return this->nom;}
     void avancer();
};

#endif // Partition_H
