#ifndef SCORE_H
#define SCORE_H

#include <QFile>
#include <QTextStream>

#include "note.h"
#include "partition.h"


using namespace std;

class Score// : public QWidget
{
   // Q_OBJECT

private:
    std::vector<Note*> notes_partition;
    std::vector<Note*> notes_clavier;
    int nbErreur;
public:
    Score();
    void log(QString);
    std::vector<int> calculErreur(std::vector<Note*>, std::vector<Note*>);


};

#endif // SCORE_H
