#ifndef CLAVIER_H
#define CLAVIER_H

#include <QPainter>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include "touche.h"


class Clavier : public QWidget
{
    Q_OBJECT

public:
    Clavier();
    void afficherClavier();
    void paintEvent(QPaintEvent *);
};

#endif // CLAVIER_H
