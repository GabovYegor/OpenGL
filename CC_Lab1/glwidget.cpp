#include "glwidget.h"

void glView::initializeGL() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 600, 0, 0, 1);
}

void glView::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
}

void glView::paintGL() {
    qglClearColor(Qt::darkCyan);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(paint_mode);
    qglColor(Qt::red);
    glVertex2i(200, 200);
    qglColor(Qt::blue);
    glVertex2i(100, 300);
    qglColor(Qt::green);
    glVertex2i(400, 400);
    qglColor(Qt::red);
    glVertex2i(500, 100);
    qglColor(Qt::blue);
    glVertex2i(200, 400);
    qglColor(Qt::green);
    glVertex2i(500, 500);
    glEnd();
}

void glView::change_mode(int value) {
    switch (value) {
    case 0: paint_mode = 0x0000; break;
    case 1: paint_mode = 0x0001; break;
    case 2: paint_mode = 0x0003; break;
    case 3: paint_mode = 0x0002; break;
    case 4: paint_mode = 0x0004; break;
    case 5: paint_mode = 0x0005; break;
    case 6: paint_mode = 0x0006; break;
    case 7: paint_mode = 0x0007; break;
    case 8: paint_mode = 0x0008; break;
    case 9: paint_mode = 0x0009; break;
    }
    updateGL();
}

