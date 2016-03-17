#ifndef PARSER_H
#define PARSER_H
#include <vector>
#include <QFile>
#include <QDomDocument>
#include <QMessageBox>
#include <iostream>

#include "note.h"

class Parser : public QWidget
{
    Q_OBJECT
public:
    Parser(QString);
    std::vector<Note *> recupereNote();
    nom_note transformer(std::string);

private:
    QDomDocument* dom;
};

#endif // PARSER_H
