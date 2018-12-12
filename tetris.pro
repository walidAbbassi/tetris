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
        src/tetris.cpp \
    src/objects/unit.cpp \
    src/objects/horse.cpp \
    src/objects/figure.cpp \
    src/objects/square.cpp \
    src/objects/straight.cpp \
    src/objects/lightning.cpp \
    src/game.cpp \
    src/gamelogic.cpp

HEADERS  += src/tetris.h \
    src/objects/unit.h \
    src/objects/horse.h \
    src/objects/figure.h \
    src/objects/square.h \
    src/objects/straight.h \
    src/objects/lightning.h \
    src/game.h \
    src/gamelogic.h

FORMS    += src/resources/tetris.ui

RESOURCES += \
    src/resources/images.qrc
CONFIG += c++11

DISTFILES += \
    README.md

DESTDIR=bin #Target file directory
OBJECTS_DIR=build #Intermediate object files directory
MOC_DIR=build #Intermediate moc files directory