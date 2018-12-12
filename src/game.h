#ifndef GAME
#define GAME
#include <QApplication>

class Game: public QApplication
{
public:
    Game(int &argc, char **argv);
    int run();
};

#endif // GAME

