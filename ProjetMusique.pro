#-------------------------------------------------
#
# Project created by QtCreator 2016-02-22T14:10:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = ProjetMusique
TEMPLATE = app


SOURCES += main.cpp\
    partition.cpp \
    note.cpp \
    clavier.cpp \
    touche.cpp \
    window.cpp \
    controleur.cpp

HEADERS  += \
    partition.h \
    note.h \
    clavier.h \
    touche.h \
    window.h \
    controleur.h

FORMS    += mainwindow.ui

RESOURCES += \
    son.qrc

DISTFILES += \
