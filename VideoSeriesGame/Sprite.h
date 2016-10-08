//
// Created by Joshua McDonald on 10/5/16.
//

#ifndef VIDEOSERIESGAME_SPRITE_H
#define VIDEOSERIESGAME_SPRITE_H

#include <OpenGL/gl3.h>
#include "GLSLProgram.h"
#include <SDL2/SDL.h>

class Sprite {

    GLuint _vboId;
    
    GLSLProgram _program;
    
    struct {
        float x;
        float y;
    } _position;
    
    float _x;
    float _y;
    float _w;
    float _h;
    
    bool handleKeydown(SDL_Event *evt);

public:

    Sprite(float x, float y, float w, float h, GLSLProgram program);
    ~Sprite();

    void init();
    void draw();

};


#endif //VIDEOSERIESGAME_SPRITE_H
