
#include <iostream>
#include "Game.h"

int main() {

    // Constructor
    Game *game = new Game();

    // Start the game
    game->start();

    // When we get here, it means we've broken out of the game loop
    return 0;

}