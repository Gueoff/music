#include "touche.h"

Touche::Touche()
{

}

Touche::Touche(Note *note){
    this->note = note;

    if(note->getNom() == A && note->getAlteration() == 1){
        this->setText("La");
    }
    else if(note->getNom() == B && note->getAlteration() == 1){
        this->setText("Si");
    }
    else if(note->getNom() == C && note->getAlteration() == 1){
        this->setText("Do");
    }
    else if(note->getNom() == D && note->getAlteration() == 1){
        this->setText("Re");
    }
    else if(note->getNom() == E && note->getAlteration() == 1){
        this->setText("Mi");
    }
    else if(note->getNom() == F && note->getAlteration() == 1){
        this->setText("Fa");
    }
    else if(note->getNom() == G && note->getAlteration() == 1){
        this->setText("Sol");
    }

    else if(note->getNom() == C && note->getAlteration() == 2){
        this->setText("Do#");
    }
    else if(note->getNom() == D && note->getAlteration() == 2){
        this->setText("Re#");
    }
    else if(note->getNom() == F && note->getAlteration() == 2){
        this->setText("Fa#");
    }
    else if(note->getNom() == G && note->getAlteration() == 2){
        this->setText("Sol#");
    }
    else if(note->getNom() == A && note->getAlteration() == 2){
        this->setText("La#");
    }




    //Blanches
    if(note->getAlteration() == 1){
        this->setStyleSheet ("QPushButton {"
                                "background-color : white;"
                                "border : 1px solid black;"
                                "width:4%;"
                                "min-width:50px;"
                                "height:100%;"
                                "min-height:250px;"
                                "color:white;"
                                "text-align: bottom;"
                              "}"
                            "QPushButton:hover {"
                            "border: 1px solid rgba(0,0,0,20%);"
                            "color:black;"
                            "}"
                             );
    }

    //Noires
    else if(note->getAlteration() == 2){
        this->setStyleSheet ("QPushButton {"
                                "background-color : black;"
                                "border : 1px solid grey;"
                                "width:4%;"
                                "min-width:30px;"
                                "height:50%;"
                                "min-height:150px;"
                                "color:black;"
                                "text-align: bottom;"
                              "}"
                            "QPushButton:hover {"
                            "border: 1px solid rgba(0,0,0,20%);"
                            "color:white;"
                            "}"
                             );

    }

}



