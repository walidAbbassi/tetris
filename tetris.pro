#-------------------------------------------------
#
# Project created by QtCreator 2018-07-22T09:25:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tetris
TEMPLATE = app


SOURCES += main.cpp\
        tetris.cpp \
    mygraphicview.cpp \
    objects/unit.cpp \
    objects/horse.cpp

HEADERS  += tetris.h \
    mygraphicview.h \
    objects/unit.h \
    objects/horse.h

FORMS    += tetris.ui
