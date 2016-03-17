#include "parser.h"

using namespace std;

/**
 * @brief Parser::Parser Constructeur du parser.
 * @param fichier le fichier à loader.
 * Doit prendre un fichier XML en entrée selon les conventions de note.
 */
Parser::Parser(QString fichier)
{
    this->dom = new QDomDocument(fichier);
    QFile xml_doc(":/partitions/"+fichier+".xml");

    if(!xml_doc.open(QIODevice::ReadOnly)){
        QMessageBox::warning(this,"Erreur à l'ouverture du document XML","Le document XML n'a pas pu être ouvert. Vérifiez que le nom est le bon et que le document est bien placé");
        return;
    }
    if(!dom->setContent(&xml_doc)){
        xml_doc.close();
        QMessageBox::warning(this,"Erreur à l'ouverture du document XML","Le document XML n'a pas pu être attribué à l'objet QDomDocument.");
        return;
    }
    xml_doc.close();
}

/**
 * @brief Parser::recupereNote
 * @return un vecteur de notes parsé à partir d'un fichier XML.
 */
vector<Note*> Parser::recupereNote(){
    QDomElement dom_element = this->dom->documentElement();
    QDomNode noeud = dom_element.firstChild();
    QDomNode noeud2;
    QDomElement elt;
    string nom;
    vector<Note*> res;
    int alteration;
    int octave;

    while(!noeud.isNull()){
        elt = noeud.toElement();
        if(!elt.isNull()){
            noeud2 = elt.firstChild();
            if(!noeud2.isNull()){
                nom = noeud2.toElement().text().toStdString();
                noeud2 = noeud2.nextSibling();
                if(!noeud2.isNull()){
                    alteration = noeud2.toElement().text().toInt();

                    noeud2 = noeud2.nextSibling();
                    if(!noeud2.isNull()){
                        octave = noeud2.toElement().text().toInt();

                        res.push_back(new Note(transformer(nom),alteration,octave));
                    }
                    else{
                        QMessageBox::warning(this,"Erreur lors de la lecture de l'octave de la note","Impossible de lire la valeur de la note");
                    }
                }
                else{
                    QMessageBox::warning(this,"Erreur lors de la lecture de la valeur de l'alteration","Impossible de lire la valeur de la note");
                }
            }
            else{
                QMessageBox::warning(this,"Erreur lors de la lecture de la valeur de la note","Impossible de lire la valeur de la note");
            }
        }
        else{
            QMessageBox::warning(this,"Erreur lors de la lecture de la partition","Impossible de lire la valeur de la note");
        }
        noeud = noeud.nextSibling();
    }

    return res;
}

/**
 * @brief Parser::transformer Transforme les String de nom de note en enum_note.
 * @param nom le nom de la note en string.
 * @return le no mde lanote en nom_note.
 */
nom_note Parser::transformer(std::string nom){
    if(nom == "A")
        return A;
    else if(nom == "B")
        return B;
    else if(nom == "C")
        return C;
    else if(nom == "D")
        return D;
    else if(nom == "E")
        return E;
    else if(nom == "F")
        return F;
    else if(nom == "G")
        return G;

    return A;
}


