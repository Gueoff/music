#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <QPushButton>
#include <QGridLayout>

class Controleur : public QWidget
{
    Q_OBJECT

public:
    Controleur();
public slots:
    void genererPartition();
private:
     QPushButton *bouton;
};

#endif // CONTROLEUR_H
