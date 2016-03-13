#include "partition.h"

using namespace std;


Partition::Partition()
{
    int interval = 12;

    QGridLayout *layout = new QGridLayout;
    layout->setAlignment(Qt::AlignAbsolute);

    QPainter painter(this);
    painter.setBackgroundMode(Qt::OpaqueMode);
    painter.setPen(Qt::black);

    painter.drawLine(5,this->height()/8+interval,this->width()-5,this->height()/8+interval);
    painter.drawLine(5,this->height()/8+2*interval,this->width()-5,this->height()/8+2*interval);
    painter.drawLine(5,this->height()/8+3*interval,this->width()-5,this->height()/8+3*interval);
    painter.drawLine(5,this->height()/8+4*interval,this->width()-5,this->height()/8+4*interval);
    painter.drawLine(5,this->height()/8+5*interval,this->width()-5,this->height()/8+5*interval);

    layout->addWidget(this);
}



void Partition::setBrush(const QBrush &brush)
{
    this->brush = brush;
    update();
}

void Partition::paintEvent(QPaintEvent *)
{
    afficherPortee();
}


void Partition::positionNote(Note *note){

}

void Partition::afficherPortee(){
    int interval = 12;

    QGridLayout *layout = new QGridLayout;

    QPainter painter(this);
    painter.setBackgroundMode(Qt::OpaqueMode);
    painter.setPen(Qt::black);

    painter.drawLine(5,this->height()/8+interval,this->width()-5,this->height()/8+interval);
    painter.drawLine(5,this->height()/8+2*interval,this->width()-5,this->height()/8+2*interval);
    painter.drawLine(5,this->height()/8+3*interval,this->width()-5,this->height()/8+3*interval);
    painter.drawLine(5,this->height()/8+4*interval,this->width()-5,this->height()/8+4*interval);
    painter.drawLine(5,this->height()/8+5*interval,this->width()-5,this->height()/8+5*interval);

    layout->addWidget(this);

}
