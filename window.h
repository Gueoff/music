#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include "clavier.h"
#include "partition.h"
#include "controleur.h"
#include "score.h"
#include "resultat.h"

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();
    void handleButton();

private slots:


private:
    Clavier *clavier;
    Partition *partition;
    Controleur *controleur;
    Score *score;
    Resultat *resultat;
};

#endif // WINDOW_H
