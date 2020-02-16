#ifndef GLVIEW_HPP
#define GLVIEW_HPP

#include <QGLWidget>

struct glView : QGLWidget {
    Q_OBJECT
    void initializeGL() override;
    void resizeGL(int w, int h)override;
    void paintGL()override;

public slots:
    void change_mode(int);

private:
    GLenum paint_mode = 0x0004;
};

#endif // GLVIEW_HPP
