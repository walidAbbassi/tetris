#include "game.h"
#include "tetris.h"
#include <QApplication>
Game::Game(int &argc, char **argv) : QApplication(argc, argv){}

int Game::run()
{
    Tetris w(this);
    w.show();

    return exec();
}
