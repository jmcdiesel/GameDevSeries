//
// Created by Joshua McDonald on 9/26/16.
//

#ifndef VIDEOSERIESGAME_GAME_H
#define VIDEOSERIESGAME_GAME_H

#include <SDL2/SDL.h>
#include <iostream>

#include "EventHandler.h"

#include "GLSLProgram.h"
#include "Sprite.h"

class Game {

    // Properties
    SDL_Window *_window;
    EventHandler _eh;
    bool _run;

    GLSLProgram _program;

    Sprite *_sprite;

    // Methods
    bool run();
    void init();
    bool initSDL();
    bool initEvents();
    bool handleQuit(SDL_Event *evt);
    bool handleKeydown(SDL_Event *evt);

public:

    Game();
    ~Game();

    void start();

};


#endif //VIDEOSERIESGAME_GAME_H
