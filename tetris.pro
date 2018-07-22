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
    objects/unit.cpp \
    objects/horse.cpp \
    gameboard.cpp \
    objects/figure.cpp \
    objects/square.cpp

HEADERS  += tetris.h \
    objects/unit.h \
    objects/horse.h \
    gameboard.h \
    objects/figure.h \
    objects/square.h

FORMS    += tetris.ui
