#include "window.h"

Window::Window() {
    glWidget = new glView;
    list = new QComboBox;

    list->addItem("GL_POINTS");
    list->addItem("GL_LINES");
    list->addItem("GL_LINE_STRIP");
    list->addItem("GL_LINE_LOOP");
    list->addItem("GL_TRIANGLES");
    list->addItem("GL_TRIANGLE_STRIP");
    list->addItem("GL_TRIANGLE_FAN");
    list->addItem("GL_QUADS");
    list->addItem("GL_QUAD_STRIP");
    list->addItem("GL_POLYGON");

    connect(list, SIGNAL(activated(int)), glWidget, SLOT(change_mode(int)));

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(glWidget);
    mainLayout->addWidget(list);
    setLayout(mainLayout);
}

void Window::keyPressEvent(QKeyEvent *e) {
    if (e->key() == Qt::Key_Escape)
        close();
}
