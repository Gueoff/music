#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <QPushButton>
#include <QGridLayout>
#include <QButtonGroup>
#include <QScrollArea>
#include "parser.h"
#include "partition.h"
#include "clavier.h"



using namespace std;

class Controleur : public QWidget
{
    Q_OBJECT

public:
    Controleur();
    Partition* getPartition(){return this->partition;}
    Clavier* getClavier(){return this->clavier;}
public slots:
    void genererPartition(int);
    void changerPartition();

private:
    bool deplie;
    Parser *parser;
    Partition *partition;
    Clavier *clavier;
    QGridLayout *layout;
    QPushButton *changer;
    QPushButton *a;
    QPushButton *b;
    QPushButton *c;
    QPushButton *d;
};

#endif // CONTROLEUR_H
