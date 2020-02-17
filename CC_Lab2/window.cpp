#include "window.h"

Window::Window() {
    glWidget = new glView;
    combobox_primitives = new QComboBox;
    initPrimitiveList(combobox_primitives, {"GL_POINTS", "GL_LINES", "GL_LINE_STRIP",
                            "GL_LINE_LOOP", "GL_TRIANGLES", "GL_TRIANGLE_STRIP", "GL_TRIANGLE_FAN",
                                            "GL_QUADS", "GL_QUAD_STRIP", "GL_POLYGON"});
    combobox_alpha_test = new QComboBox;
    initPrimitiveList(combobox_alpha_test, {"GL_NEVER", "GL_LESS", "GL_EQUAL", "GL_LEQUAL",
                                            "GL_GREATER", "GL_NOTEQUAL", "GL_GEQUAL", "GL_ALWAYS"});
    combobox_blend_test_sfactor = new QComboBox;
    initPrimitiveList(combobox_blend_test_sfactor, {"GL_ZERO", "GL_ONE", "GL_DST_COLOR", "GL_ONE_MINUS_DST_COLOR",
                                                    "GL_SRC_COLOR", "GL_ONE_MINUS_SRC_ALPHA", "GL_DST_ALPHA",
                                                    "GL_ONE_MINUS_DST_ALPHA", "GL_SRC_ALPHA_SATURATE"});
    combobox_blend_test_dfactor = new QComboBox;
    initPrimitiveList(combobox_blend_test_dfactor, {"GL_ZERO", "GL_ONE", "GL_SRC_COLOR", "GL_ONE_MINUS_SRC_COLOR",
                                                    "GL_SRC_ALPHA", "GL_ONE_MINUS_SRC_ALPHA", "GL_DST_ALPHA",
                                                    "GL_ONE_MINUS_DST_ALPHA"});

    slider_alpha_test = new QSlider(Qt::Horizontal);
    slider_scissor_test = new QSlider(Qt::Horizontal);
    initSlider(slider_alpha_test, glWidget->get_alpha_test_indicator() * 100, 100);
    initSlider(slider_scissor_test, glWidget->get_scissor_test_indicator(), 800);
    lbl_alpha_test = new QLabel("Alpha test indicator value");
    lbl_scissor_test = new QLabel("Scissor test indicator value");
    initConnection();
    initLayout();
}

void Window::initLayout(){
    QHBoxLayout* mainLayout = new QHBoxLayout;
    QVBoxLayout* widgetsLayout = new QVBoxLayout;
    GLuint height_between = 50;
    mainLayout->addWidget(glWidget);
    widgetsLayout->addWidget(combobox_primitives);
    widgetsLayout->addSpacing(height_between);
    widgetsLayout->addWidget(combobox_alpha_test);
    widgetsLayout->addWidget(lbl_alpha_test);
    widgetsLayout->addWidget(slider_alpha_test);
    widgetsLayout->addSpacing(height_between);
    widgetsLayout->addWidget(lbl_scissor_test);
    widgetsLayout->addWidget(slider_scissor_test);
    widgetsLayout->addSpacing(height_between);
    widgetsLayout->addWidget(combobox_blend_test_sfactor);
    widgetsLayout->addWidget(combobox_blend_test_dfactor);
    widgetsLayout->addStretch();
    mainLayout->addLayout(widgetsLayout);
    setLayout(mainLayout);
}

void Window::initConnection() {
    connect(combobox_primitives, SIGNAL(activated(int)), glWidget, SLOT(change_primitive_mode(int)));
    connect(combobox_alpha_test, SIGNAL(activated(int)), glWidget, SLOT(change_alpha_test_mode(int)));
    connect(slider_alpha_test, SIGNAL(valueChanged(int)), glWidget, SLOT(change_alpha_test_indicator(int)));
    connect(slider_scissor_test, SIGNAL(valueChanged(int)), glWidget, SLOT(change_scissor_test_indicator(int)));
    connect(combobox_blend_test_sfactor, SIGNAL(activated(int)), glWidget, SLOT(change_blend_test_sfactor(int)));
    connect(combobox_blend_test_dfactor, SIGNAL(activated(int)), glWidget, SLOT(change_blend_test_dfactor(int)));
}

void Window::initSlider(QSlider* slider, GLfloat value, GLint maxSliderValue) {
    slider->setFixedWidth(200);
    slider->setRange(1, maxSliderValue);
    slider->setSingleStep(1);
    slider->setValue(value);
}

void Window::initPrimitiveList(QComboBox* combo_box, QVector<QString> combobox_primitives_values) {
    for(auto it: combobox_primitives_values)
        combo_box->addItem(it);
}

void Window::keyPressEvent(QKeyEvent *e) {
    if (e->key() == Qt::Key_Escape)
        close();
}
