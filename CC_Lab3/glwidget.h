#ifndef GLVIEW_HPP
#define GLVIEW_HPP

#include <QGLWidget>

#include <vector>

struct Triangle {
    Triangle() = default;
    Triangle(QPointF a, QPointF b, QPointF c) : points{a, b, c} {}
    Triangle(QVector <QPointF> points) : points(points) {}
    QVector <QPointF> points;
};

struct glView : QGLWidget {
private:
    void initializeGL() override;
    void resizeGL(int w, int h)override;
    void paintGL()override;

    void drawLogic(const Triangle &triangle, int reqursionDeep, int test);
    int reqursionDeep;
    int reqursionVecHelper;
    int iterationNumber = 2;
    std::vector <QPointF> reqursionVec;
    std::vector <QPointF> tempVec;
};

#endif // GLVIEW_HPP
