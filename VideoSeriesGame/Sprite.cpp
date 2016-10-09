//
// Created by Joshua McDonald on 10/5/16.
//

#include "Sprite.h"
#include "Game.h"
#include "vertexData.h"

#include <cstddef>

Sprite::Sprite(float x, float y, float w, float h, GLSLProgram program) {
    _x = x;
    _y = y;
    _w = w;
    _h = h;
    
    _program = program;
    
    _vboId = 0;
    
    init();
}

Sprite::~Sprite() {
    if(_vboId) {
        glDeleteBuffers(1, &_vboId);
    }
}

void Sprite::init() {
    using namespace std::placeholders;
    EventHandler::registerEvent(SDL_KEYDOWN, std::bind(&Sprite::handleKeydown, this, _1));
    
    if (_vboId == 0) {
        glGenBuffers(1, &_vboId);
    }
    
    vertexData vData[6];

    vData[0].position.x = _x + _w;
    vData[0].position.y = _y + _w;
    
    vData[1].position.x = _x;
    vData[1].position.y = _y + _h;

    vData[2].position.x = _x;
    vData[2].position.y = _y;

    vData[3].position.x = _x;
    vData[3].position.y = _y;

    vData[4].position.x = _x + _w;
    vData[4].position.y = _y;

    vData[5].position.x = _x + _w;
    vData[5].position.y = _y + _h;
    
    vData[0].color.r = 1.0;
    vData[0].color.g = 1.0;
    vData[0].color.b = 1.0;
    vData[0].color.a = 1.0;
    
    vData[1].color.r = 1.0;
    vData[1].color.g = 1.0;
    vData[1].color.b = 1.0;
    vData[1].color.a = 1.0;
    
    vData[2].color.r = 1.0;
    vData[2].color.g = 1.0;
    vData[2].color.b = 1.0;
    vData[2].color.a = 1.0;
    
    vData[3].color.r = 1.0;
    vData[3].color.g = 1.0;
    vData[3].color.b = 1.0;
    vData[3].color.a = 1.0;
    
    vData[4].color.r = 1.0;
    vData[4].color.g = 1.0;
    vData[4].color.b = 1.0;
    vData[4].color.a = 1.0;
    
    vData[5].color.r = 1.0;
    vData[5].color.g = 1.0;
    vData[5].color.b = 1.0;
    vData[5].color.a = 1.0;
    
    
    // Bind the buffer and send the data
    glBindBuffer(GL_ARRAY_BUFFER, _vboId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vData), vData, GL_STATIC_DRAW);

    // unbind the buffer
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

bool Sprite::handleKeydown(SDL_Event *evt) {

    switch(evt->key.keysym.scancode) {
        case SDL_SCANCODE_RIGHT:
            _position.x += 0.01f;
            break;
        case SDL_SCANCODE_LEFT:
            _position.x -= 0.01f;
            break;
        case SDL_SCANCODE_UP:
            _position.y += 0.01f;
            break;
        case SDL_SCANCODE_DOWN:
            _position.y -= 0.01f;
            break;
        default:
            break;
    }
    
    return true;
}

void Sprite::draw() {
    
    glBindBuffer(GL_ARRAY_BUFFER, _vboId);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(vertexData), (void *)offsetof(vertexData, position));
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(vertexData), (void *)offsetof(vertexData, color));
    
    printf("%lu, %lu, %lu \n", sizeof(vertexData), offsetof(vertexData, position), offsetof(vertexData, color));

    GLuint locTranslate = glGetUniformLocation(_program.getProgramId(), "translate");
    glUniform2f(locTranslate, _position.x, _position.y);
    
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    SDL_Delay(500);
}
