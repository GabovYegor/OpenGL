#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QComboBox>
#include <QtGui>
#include <QHBoxLayout>

#include "glwidget.h"

class Window : public QWidget {
    Q_OBJECT

public:
    Window();
    glView *glWidget;
protected:
    void keyPressEvent(QKeyEvent *event);
private:
    QComboBox* list;
};

#endif
