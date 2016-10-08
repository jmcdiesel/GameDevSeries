//
// Created by Joshua McDonald on 9/26/16.
//

#include "Game.h"

SDL_Window *Game::_window;

bool Game::_run = true;

GLSLProgram Game::_program;

Sprite *Game::_sprite;

// Kick off the game loop

void Game::start() {
    
    try {
    init();
    } catch (std::runtime_error &ex) {
        std::cout << "Init Error: " << ex.what() << std::endl;
        return;
    }

    while(Game::run()) {

    }

    SDL_Quit();

}

// Game Loop

bool Game::run() {

    _run = EventHandler::handleEvents();

    //Set the base depth to 1.0
    glClearDepth(1.0);
    //Clear the color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    _program.use();

    _sprite->draw();

    _program.unuse();
    SDL_GL_SwapWindow(_window);

    return _run;
}

// Initializers

void Game::init() {

    Game::initSDL();
    Game::initEvents();

    _sprite = new Sprite(-0.5f, -0.5f, 1.0f, 1.0f, _program);

}

bool Game::initSDL() {

    _window = SDL_CreateWindow("Awesome Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);

    if(_window == NULL) {
        std::cout << "Could Not Initialize Window: " << SDL_GetError();
        SDL_Quit();
        return false;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );

    //Set up our OpenGL context
    SDL_GLContext glContext = SDL_GL_CreateContext(_window);
    if (glContext == nullptr) {
        throw std::runtime_error("SDL_GL context could not be created!");
    }

    GLuint vertexArrayID;
    glGenVertexArrays(1, &vertexArrayID);
    glBindVertexArray(vertexArrayID);

    //Tell SDL that we want a double buffered window so we dont get
    //any flickering
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    //Set the background color to blue
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    Game::_program.compileShaders("shaders/ColorShader.vert", "shaders/ColorShader.frag");

    return true;
}

bool Game::initEvents() {
    using namespace std::placeholders;

    EventHandler::registerEvent(SDL_QUIT, Game::handleQuit);
    EventHandler::registerEvent(SDL_KEYDOWN, Game::handleKeydown);

    return true;
}

// Handlers

bool Game::handleQuit(SDL_Event *evt) {
    std::cout << "Quitting!";
    return false;
}

bool Game::handleKeydown(SDL_Event *evt) {

    switch(evt->key.keysym.scancode) {
        case SDL_SCANCODE_SPACE:
            std::cout << "YOU HIT SPACE!  YOU WIN SPACE!" << std::endl;
            break;
        default:
            break;
    }

    return true;
}
