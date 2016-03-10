#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include "clavier.h"
#include "partition.h"
#include "controleur.h"

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

};

#endif // WINDOW_H
