#include <iostream>

#ifndef MOLTENVKCPP_GAME_H
#define MOLTENVKCPP_GAME_H

class Game {
private:
    int counter = 0;

public:
    void tick();

    void terminate();
};


#endif //MOLTENVKCPP_GAME_H
