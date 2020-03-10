#include "window.h"
#include <QHBoxLayout>

Window::Window() {
    glWidget = new glView;
    QHBoxLayout * mainLayout = new QHBoxLayout;
    mainLayout->addWidget(glWidget);
    setLayout(mainLayout);
}

void Window::keyPressEvent(QKeyEvent *e) {
    if (e->key() == Qt::Key_Escape)
        close();
}
