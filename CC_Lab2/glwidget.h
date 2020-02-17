#ifndef GLVIEW_HPP
#define GLVIEW_HPP

#include <QGLWidget>

struct glView : QGLWidget {
    Q_OBJECT

public:
    glView();
    void initializeGL() override;
    void resizeGL(int w, int h)override;
    void paintGL()override;
    GLfloat get_alpha_test_indicator() { return alpha_test_indicator; }
    GLfloat get_scissor_test_indicator() { return scissor_test_indicator; }

public slots:
    void change_primitive_mode(int);
    void change_alpha_test_mode(int);
    void change_alpha_test_indicator(int);
    void change_scissor_test_indicator(int);
    void change_blend_test_sfactor(int);
    void change_blend_test_dfactor(int);

private:
    GLenum primitive_mode;
    GLuint win_weight;
    GLuint win_height;
    GLfloat alpha_test_indicator;
    GLenum alpha_test_mode;
    GLfloat scissor_test_indicator;
    GLenum blend_sfactor_mode;
    GLenum blend_dfactor_mode;
};

#endif //
