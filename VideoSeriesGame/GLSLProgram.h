//
// Created by Joshua McDonald on 10/5/16.
//

#ifndef VIDEOSERIESGAME_GLSLPROGRAM_H
#define VIDEOSERIESGAME_GLSLPROGRAM_H

#import <OpenGL/gl3.h>
#include <string>
#include <vector>

class GLSLProgram {

    GLuint _programId;
    GLuint _vertexShaderId;
    GLuint _fragmentShaderId;

    void linkShaders();
    void compileShader(GLuint shaderId, std::vector<char> source);

public:

    GLSLProgram();

    void compileShaders(std::string vertexPath, std::string fragmentPath);
    void use();
    void unuse();


};


#endif //VIDEOSERIESGAME_GLSLPROGRAM_H
