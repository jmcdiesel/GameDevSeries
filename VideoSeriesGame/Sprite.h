//
// Created by Joshua McDonald on 10/5/16.
//

#ifndef VIDEOSERIESGAME_SPRITE_H
#define VIDEOSERIESGAME_SPRITE_H

#include <OpenGL/gl3.h>

class Sprite {

    GLuint _vboId;

    float _x;
    float _y;
    float _w;
    float _h;

public:

    Sprite(float x, float y, float w, float h);
    ~Sprite();

    void init();
    void draw();

};


#endif //VIDEOSERIESGAME_SPRITE_H
