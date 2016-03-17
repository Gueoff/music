#-------------------------------------------------
#
# Project created by QtCreator 2016-02-22T14:10:33
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = ProjetMusique
TEMPLATE = app


SOURCES += main.cpp\
    partition.cpp \
    note.cpp \
    clavier.cpp \
    touche.cpp \
    window.cpp \
    controleur.cpp \
    parser.cpp \
    score.cpp \
    resultat.cpp

HEADERS  += \
    partition.h \
    note.h \
    clavier.h \
    touche.h \
    window.h \
    controleur.h \
    parser.h \
    score.h \
    resultat.h

FORMS    += mainwindow.ui

RESOURCES += \
    sons.qrc \
    partitions.qrc


DISTFILES += \

