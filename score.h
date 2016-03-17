#ifndef SCORE_H
#define SCORE_H

#include <QPushButton>
#include <QGridLayout>
#include <QButtonGroup>
#include <QFile>
#include <QTextStream>
#include <QLabel>
#include <QPainter>
#include "note.h"
#include "partition.h"


using namespace std;

class Score : public QWidget
{
    Q_OBJECT

private:
    std::vector<Note*> notes_partition;
    std::vector<Note*> notes_clavier;

    int nbErreur;
public:
    Score();
    void afficherScore(std::vector<Note*>, std::vector<Note*>);
    void log();
    std::vector<int> calculErreur(std::vector<Note*>, std::vector<Note*>);

public slots:
   // void retour();

};

#endif // SCORE_H
