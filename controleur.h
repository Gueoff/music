#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <QPushButton>
#include <QGridLayout>
#include <QButtonGroup>
#include <QScrollArea>
#include "parser.h"



using namespace std;

class Controleur : public QWidget
{
    Q_OBJECT

public:
    Controleur();
public slots:
    void genererPartition(int);
    void changerPartition();
private:
    bool deplie;
    Parser *parser;
    QGridLayout *layout;
    QPushButton *changer;
    QPushButton *a;
    QPushButton *b;
    QPushButton *c;
    QPushButton *d;
};

#endif // CONTROLEUR_H
