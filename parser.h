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
    Parser();
    std::vector<Note *> recupereNote();

private:
    QDomDocument* dom;
};

#endif // PARSER_H
