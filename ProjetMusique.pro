#-------------------------------------------------
#
# Project created by QtCreator 2016-02-22T14:10:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetMusique
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    partition.cpp \
    note.cpp

HEADERS  += mainwindow.h \
    partition.h \
    note.h

FORMS    += mainwindow.ui
