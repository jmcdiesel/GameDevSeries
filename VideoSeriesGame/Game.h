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
    static SDL_Window *_window;
    static EventHandler _eh;
    static bool _run;

    static GLSLProgram _program;

    static Sprite *_sprite;

    // Methods
    static bool run();
    static void init();
    static bool initSDL();
    static bool initEvents();
    static bool handleQuit(SDL_Event *evt);
    static bool handleKeydown(SDL_Event *evt);

public:

    static void start();

};


#endif //VIDEOSERIESGAME_GAME_H
