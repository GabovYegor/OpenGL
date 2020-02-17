#include "glwidget.h"

glView::glView() {
    primitive_mode = 0x0004;
    win_height = 600;
    win_weight = 800;
    alpha_test_indicator = 0.7;
    alpha_test_mode = 0x0207;
    scissor_test_indicator = 500;
    blend_sfactor_mode = GL_ONE;
    blend_dfactor_mode = GL_ZERO;
}

void glView::initializeGL() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, win_weight, win_height, 0, 0, 1);
}

void glView::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
}

inline void addPoints() {
    // 1
    glColor4f(0.4, 0.2, 0.0, 0.2);
    glVertex2i(100, 300);
    // 2
    glColor4f(0.2, 0.4, 0.8, 0.4);
    glVertex2i(400, 400);
    // 3
    glColor4f(0.1, 0.3, 0.7, 0.6);
    glVertex2i(500, 100);
    // 4
    glColor4f(0.2, 0.1, 1.0, 0.8);
    glVertex2i(600, 500);
    // 5
    glColor4f(1, 0.4, 0.2, 0.9);
    glVertex2i(50, 600);
    // 6
    glColor4f(0.2, 0.3, 0.4, 0.9);
    glVertex2i(250, 50);
}

void glView::paintGL() {
    qglClearColor(Qt::darkCyan);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glScissor(0, 0, scissor_test_indicator, scissor_test_indicator);
    glAlphaFunc(alpha_test_mode, alpha_test_indicator);
    glBlendFunc(blend_sfactor_mode, blend_dfactor_mode);
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_SCISSOR_TEST);
    glEnable(GL_BLEND);
    glBegin(primitive_mode);
    addPoints();
    glEnd();
    glDisable(GL_BLEND);
    glDisable(GL_SCISSOR_TEST);
    glDisable(GL_ALPHA_TEST);
}

void glView::change_primitive_mode(int value) {
    switch (value) {
    case 0: primitive_mode = 0x0000; break;
    case 1: primitive_mode = 0x0001; break;
    case 2: primitive_mode = 0x0003; break;
    case 3: primitive_mode = 0x0002; break;
    case 4: primitive_mode = 0x0004; break;
    case 5: primitive_mode = 0x0005; break;
    case 6: primitive_mode = 0x0006; break;
    case 7: primitive_mode = 0x0007; break;
    case 8: primitive_mode = 0x0008; break;
    case 9: primitive_mode = 0x0009; break;
    }
    updateGL();
}

void glView::change_alpha_test_mode(int value) {
    switch (value) {
    case 0: alpha_test_mode = 0x0200; break;
    case 1: alpha_test_mode = 0x0201; break;
    case 2: alpha_test_mode = 0x0202; break;
    case 3: alpha_test_mode = 0x0203; break;
    case 4: alpha_test_mode = 0x0204; break;
    case 5: alpha_test_mode = 0x0205; break;
    case 6: alpha_test_mode = 0x0206; break;
    case 7: alpha_test_mode = 0x0207; break;
    }
    updateGL();
}

void glView::change_alpha_test_indicator(int value) {
    alpha_test_indicator = (GLfloat) value / 100;
    updateGL();
}

void glView::change_scissor_test_indicator(int value) {
    scissor_test_indicator = value;
    updateGL();
}

void glView::change_blend_test_sfactor(int value) {
    switch (value) {
    case 0: blend_sfactor_mode = 0; break;
    case 1: blend_sfactor_mode = 1; break;
    case 2: blend_sfactor_mode = 0x0306; break;
    case 3: blend_sfactor_mode = 0x0307; break;
    case 4: blend_sfactor_mode = 0x0300; break;
    case 5: blend_sfactor_mode = 0x0303; break;
    case 6: blend_sfactor_mode = 0x0304; break;
    case 7: blend_sfactor_mode = 0x0305; break;
    case 8: blend_sfactor_mode = 0x0308; break;
    }
    updateGL();
}

void glView::change_blend_test_dfactor(int value) {
    switch (value) {
    case 0: blend_dfactor_mode = 0; break;
    case 1: blend_dfactor_mode = 1; break;
    case 2: blend_dfactor_mode = 0x0300; break;
    case 3: blend_dfactor_mode = 0x0301; break;
    case 4: blend_dfactor_mode = 0x0302; break;
    case 5: blend_dfactor_mode = 0x0303; break;
    case 6: blend_dfactor_mode = 0x0304; break;
    case 7: blend_dfactor_mode = 0x0305; break;
    }
    updateGL();
}
