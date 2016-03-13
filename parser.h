#ifndef PARSER_H
#define PARSER_H
#include <vector>
#include "note.h"
#include <QFile>
#include <QDomDocument>
#include <QMessageBox>
#include <iostream>

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
