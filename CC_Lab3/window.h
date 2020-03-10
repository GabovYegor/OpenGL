#ifndef WINDOW_H
#define WINDOW_H

#include <QtGui>
#include <QWidget>
#include <QPushButton>
#include "glwidget.h"

class Window : public QWidget {
    Q_OBJECT

public:
    Window();
    glView * glWidget;
protected:
    void keyPressEvent(QKeyEvent * event);
};

#endif
