#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QtGui>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include <QSlider>
#include <QLabel>

#include "glwidget.h"

class Window : public QWidget {
    Q_OBJECT

public:
    Window();
    glView *glWidget;
protected:
    void keyPressEvent(QKeyEvent *event);
private:
    QComboBox* combobox_primitives;
    QComboBox* combobox_alpha_test;
    QComboBox* combobox_blend_test_sfactor;
    QComboBox* combobox_blend_test_dfactor;
    QSlider* slider_alpha_test;
    QSlider* slider_scissor_test;
    QLabel* lbl_alpha_test;
    QLabel* lbl_scissor_test;


    void initPrimitiveList(QComboBox* combo_box, QVector<QString> combobox_primitives_values);
    void initSlider(QSlider* slider, GLfloat value, GLint maxSliderValue);
    void initConnection();
    void initLayout();
};

#endif
