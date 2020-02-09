#ifndef FUNCTIONS
#define FUNCTIONS

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <SOIL.h>
#include <vector>
#include "CameraClass/Camera.h"

const GLuint screenWidth = 800, screenHeight = 600;

GLFWwindow* initOpenGL();
GLuint createTexture(std::string textureImagePath);
std::vector<GLfloat> generateCubeVertex(GLfloat cubeSideSize);
void setUpBuffers(std::vector<GLfloat> vertices, GLuint& VBO, GLuint& VAO);

#endif
