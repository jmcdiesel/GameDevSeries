//
// Created by Joshua McDonald on 10/5/16.
//

#include "Sprite.h"
#include "Game.h"

Sprite::Sprite(float x, float y, float w, float h, GLSLProgram program) {
    _x = x;
    _y = y;
    _w = w;
    _h = h;
    
    _program = program;
    
    _vboId = 0;
    
    _position.x = 0;
    _position.y = 0;
    
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

    float vertexData[12];

    vertexData[0] = _x + _w;
    vertexData[1] = _y + _w;

    vertexData[2] = _x;
    vertexData[3] = _y + _h;

    vertexData[4] = _x;
    vertexData[5] = _y;

    vertexData[6] = _x;
    vertexData[7] = _y;

    vertexData[8] = _x + _w;
    vertexData[9] = _y;

    vertexData[10] = _x + _w;
    vertexData[11] = _y + _h;

    // Bind the buffer and send the data
    glBindBuffer(GL_ARRAY_BUFFER, _vboId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

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

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    
    GLuint locTranslate = glGetUniformLocation(_program.getProgramId(), "translate");
    glUniform2f(locTranslate, _position.x, _position.y);
    
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}
