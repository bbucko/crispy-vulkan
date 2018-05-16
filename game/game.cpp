
#include "game.h"

void Game::tick() {
    counter++;
}

void Game::terminate() {
    std::cout << "Frames rendered: " << counter << std::endl;
}
