#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <QPushButton>
#include <QGridLayout>
#include <QButtonGroup>
#include <QScrollArea>
#include <QStringList>
#include <QDirIterator>

#include "parser.h"
#include "partition.h"
#include "clavier.h"



using namespace std;

class Controleur : public QScrollArea
{
    Q_OBJECT

public:
    Controleur();
    Partition* getPartition(){return this->partition;}
    Clavier* getClavier(){return this->clavier;}
public slots:
    void genererPartition(int);

private:
    bool deplie;
    Parser *parser;
    Partition *partition;
    Clavier *clavier;
    QGridLayout *layout;
    int nombre_partitions;
};

#endif // CONTROLEUR_H
