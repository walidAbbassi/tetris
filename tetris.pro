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
    objects/figure.cpp \
    objects/square.cpp \
    objects/straight.cpp \
    objects/lightning.cpp \
    game.cpp \
    gamelogic.cpp

HEADERS  += tetris.h \
    objects/unit.h \
    objects/horse.h \
    objects/figure.h \
    objects/square.h \
    objects/straight.h \
    objects/lightning.h \
    game.h \
    gamelogic.h

FORMS    += tetris.ui

RESOURCES += \
    images.qrc
CONFIG += c++11

DISTFILES += \
    README.md
