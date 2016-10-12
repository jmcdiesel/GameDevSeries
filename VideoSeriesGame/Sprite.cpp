//
// Created by Joshua McDonald on 10/5/16.
//

#include "Sprite.h"
#include "Game.h"

#include "Vertex.h"

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

    Vertex vertexData[12];

    vertexData[0].position.x = _x + _w;
    vertexData[0].position.y = _y + _w;

    vertexData[1].position.x = _x;
    vertexData[1].position.y = _y + _h;

    vertexData[2].position.x = _x;
    vertexData[2].position.y = _y;

    vertexData[3].position.x = _x;
    vertexData[3].position.y = _y;

    vertexData[4].position.x = _x + _w;
    vertexData[4].position.y = _y;

    vertexData[5].position.x = _x + _w;
    vertexData[5].position.y = _y + _h;

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
    glEnableVertexAttribArray(1);
    
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, position));
    glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void *)offsetof(Vertex, color));
    
    GLuint locTranslate = glGetUniformLocation(_program.getProgramId(), "translate");
    glUniform2f(locTranslate, _position.x, _position.y);
    
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}
