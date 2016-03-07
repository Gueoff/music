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
     QBrush brush;
     std::vector<Note> liste_notes;
     void positionNote(Note *note);

public:
    Partition();
    void paintEvent(QPaintEvent *);
    void setBrush(const QBrush &brush);
    void afficherPortee();


};

#endif // Partition_H
