//
// Created by Joshua McDonald on 10/5/16.
//

#include <iostream>
#include "GLSLProgram.h"
#include "ResourceManager.h"


void GLSLProgram::linkShaders() {
    glAttachShader(_programId, _vertexShaderId);
    glAttachShader(_programId, _fragmentShaderId);

    glLinkProgram(_programId);

    GLint isLinked = 0;
    glGetProgramiv(_programId, GL_LINK_STATUS, (int *)&isLinked);
    if(isLinked == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetProgramiv(_programId, GL_INFO_LOG_LENGTH, &maxLength);

        //The maxLength includes the NULL character
        std::vector<GLchar> infoLog(maxLength);
        glGetProgramInfoLog(_programId, maxLength, &maxLength, &infoLog[0]);

        //We don't need the program anymore.
        glDeleteProgram(_programId);
        //Don't leak shaders either.
        glDeleteShader(_vertexShaderId);
        glDeleteShader(_fragmentShaderId);

        std::string err = std::string(infoLog.begin(), infoLog.end());
        throw std::runtime_error("Could not link shaders: " + err);
    } else {
        std::cout << "Shaders Linked" << std::endl;
    }

    glDetachShader(_programId, _vertexShaderId);
    glDetachShader(_programId, _fragmentShaderId);
}

void GLSLProgram::compileShader(GLuint shader, std::vector<char> source) {

    std::string str_source = std::string(source.begin(), source.end());
    const GLchar *src = str_source.c_str();

    glShaderSource(shader, 1, &src, NULL);
    glCompileShader(shader);

    GLint success = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(success == GL_FALSE) {
        GLint maxLength = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

        // The maxLength includes the NULL character
        std::vector<GLchar> errorLog(maxLength);
        glGetShaderInfoLog(shader, maxLength, &maxLength, &errorLog[0]);

        glDeleteShader(shader); // Don't leak the shader.
        std::string err = std::string(errorLog.begin(), errorLog.end());
        throw std::runtime_error("Could not compile shader: " + err);
    } else {
        std::printf("Shader Compiled (%d)\n", shader);
    }


}

void GLSLProgram::compileShaders(std::string vertexPath, std::string fragmentPath) {
    _programId = glCreateProgram();

    _vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    _fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

    std::vector<char> vertexShaderBuffer;
    std::vector<char> fragmentShaderBuffer;

    ResourceManager::loadFileToBuffer(vertexPath, vertexShaderBuffer);
    ResourceManager::loadFileToBuffer(fragmentPath, fragmentShaderBuffer);

    compileShader(_vertexShaderId, vertexShaderBuffer);
    compileShader(_fragmentShaderId, fragmentShaderBuffer);

}

void GLSLProgram::registerAttribute(std::string attr) {
    glBindAttribLocation(_programId, _attrCount, attr.c_str());
    _attrCount += 1;
}

void GLSLProgram::use() {
    glUseProgram(_programId);
}

void GLSLProgram::unuse() {
    glUseProgram(0);
}

GLuint GLSLProgram::getProgramId() {
    return _programId;
}

GLSLProgram::GLSLProgram() :
    _programId(0),
    _vertexShaderId(0),
    _fragmentShaderId(0),
    _attrCount(0)
{

}
