#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>

class Shader
{
public:
    GLuint Program;
    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
    void Use();
    GLuint compileShader(std::string shaderType, const GLchar * shaderCode);
    void checkSuccessCompile(GLuint shader);
    void checkSuccessLink();
};

#endif
