#include "functions.h"

GLFWwindow* initOpenGL() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_SAMPLES, 4);

    GLFWwindow* window = glfwCreateWindow(screenWidth, screenHeight, "LearnOpenGL", nullptr, nullptr); // Windowed
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    glewInit();
    glViewport(0, 0, screenWidth, screenHeight);
    glEnable(GL_DEPTH_TEST);
    return window;
}

GLuint createTexture(std::string textureImagePath) {
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width, height;
    unsigned char* image = SOIL_load_image(textureImagePath.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);
    return texture;
}

void setUpBuffers(std::vector<GLfloat> vertices, GLuint& VBO, GLuint& VAO) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);
    glBindVertexArray(0);
}

std::vector<GLfloat> generateCubeVertex(GLfloat cubeSideSize) {
    std::vector<GLfloat> vertices = {
            -cubeSideSize, -cubeSideSize, -cubeSideSize,  0.0f, 0.0f,
            cubeSideSize, -cubeSideSize, -cubeSideSize,   1.0f, 0.0f,
            cubeSideSize,  cubeSideSize, -cubeSideSize,  1.0f, 1.0f,
            cubeSideSize,  cubeSideSize, -cubeSideSize,  1.0f, 1.0f,
            -cubeSideSize,  cubeSideSize, -cubeSideSize,  0.0f, 1.0f,
            -cubeSideSize, -cubeSideSize, -cubeSideSize,  0.0f, 0.0f,

            -cubeSideSize, -cubeSideSize,  cubeSideSize, 0.0f, 0.0f,
            cubeSideSize, -cubeSideSize,  cubeSideSize,  1.0f, 0.0f,
            cubeSideSize,  cubeSideSize,  cubeSideSize,  1.0f, 1.0f,
            cubeSideSize,  cubeSideSize,  cubeSideSize,  1.0f, 1.0f,
            -cubeSideSize,  cubeSideSize,  cubeSideSize,  0.0f, 1.0f,
            -cubeSideSize, -cubeSideSize,  cubeSideSize,  0.0f, 0.0f,

            -cubeSideSize,  cubeSideSize,  cubeSideSize,  1.0f, 0.0f,
            -cubeSideSize,  cubeSideSize, -cubeSideSize,  1.0f, 1.0f,
            -cubeSideSize, -cubeSideSize, -cubeSideSize,  0.0f, 1.0f,
            -cubeSideSize, -cubeSideSize, -cubeSideSize,  0.0f, 1.0f,
            -cubeSideSize, -cubeSideSize,  cubeSideSize,  0.0f, 0.0f,
            -cubeSideSize,  cubeSideSize,  cubeSideSize,  1.0f, 0.0f,

            cubeSideSize,  cubeSideSize,  cubeSideSize,  1.0f, 0.0f,
            cubeSideSize,  cubeSideSize, -cubeSideSize,  1.0f, 1.0f,
            cubeSideSize, -cubeSideSize, -cubeSideSize,  0.0f, 1.0f,
            cubeSideSize, -cubeSideSize, -cubeSideSize,  0.0f, 1.0f,
            cubeSideSize, -cubeSideSize,  cubeSideSize,  0.0f, 0.0f,
            cubeSideSize,  cubeSideSize,  cubeSideSize,  1.0f, 0.0f,

            -cubeSideSize, -cubeSideSize, -cubeSideSize,  0.0f, 1.0f,
            cubeSideSize, -cubeSideSize, -cubeSideSize,  1.0f, 1.0f,
            cubeSideSize, -cubeSideSize,  cubeSideSize,  1.0f, 0.0f,
            cubeSideSize, -cubeSideSize,  cubeSideSize,  1.0f, 0.0f,
            -cubeSideSize, -cubeSideSize,  cubeSideSize,  0.0f, 0.0f,
            -cubeSideSize, -cubeSideSize, -cubeSideSize,  0.0f, 1.0f,

            -cubeSideSize,  cubeSideSize, -cubeSideSize,  0.0f, 1.0f,
            cubeSideSize,  cubeSideSize, -cubeSideSize,  1.0f, 1.0f,
            cubeSideSize,  cubeSideSize,  cubeSideSize,  1.0f, 0.0f,
            cubeSideSize,  cubeSideSize,  cubeSideSize,  1.0f, 0.0f,
            -cubeSideSize,  cubeSideSize,  cubeSideSize,  0.0f, 0.0f,
            -cubeSideSize,  cubeSideSize, -cubeSideSize,  0.0f, 1.0f
        };
        return vertices;
}
