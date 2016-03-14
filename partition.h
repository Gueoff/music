#ifndef PARTITION_H
#define PARTITION_H

#include <QPainter>
#include <QBrush>
#include <QWidget>
#include <QGridLayout>
#include <vector>
#include "note.h"


class Partition : public QWidget
{

    Q_OBJECT

private:
     std::vector<Note*> liste_notes;
     int interval;

public:
     Partition();
     Partition(std::vector<Note*> liste_notes){this->liste_notes = liste_notes; this->interval = 12;}
     void paintEvent(QPaintEvent *);
     void afficherPortee();
     void afficherNote(Note* ,int);
     void setListeNotes(std::vector<Note*> liste_notes){this->liste_notes = liste_notes;}
     std::vector<Note*> getListeNotes(){ return this->liste_notes;}

};

#endif // Partition_H
