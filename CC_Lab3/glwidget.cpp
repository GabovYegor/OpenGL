#include "glwidget.h"

#include <cmath>

double computeLength( const QPointF& lhs, const QPointF& rhs ) {
    return sqrt( pow(lhs.x() - rhs.x(), 2) + pow(lhs.y() - rhs.y(), 2) );
}

std::tuple <QPointF, QPointF, QPointF> findStartPoint( const Triangle& triangle ) {
    std::vector< std::pair<int, double>> sideSizes;
    for(const auto& it: std::vector < std::vector <int>> {{0, 1, 2}, {1, 0, 2}, {2, 0, 1}})
        sideSizes.emplace_back(
            std::make_pair(it[0], computeLength(triangle.points[it[1]], triangle.points[it[2]])));
    int maxElementNum = std::max_element(sideSizes.begin(), sideSizes.end(),
        [] (const auto& lhs, const auto& rhs) {return lhs.second < rhs.second; } )->first;
    int minElementNum = std::min_element(sideSizes.begin(), sideSizes.end(),
        [] (const auto& lhs, const auto& rhs) {return lhs.second < rhs.second; } )->first;
    return std::make_tuple (triangle.points[minElementNum],
                            triangle.points[3 - minElementNum - maxElementNum],
            triangle.points[maxElementNum]);
}


void glView::drawLogic(const Triangle& triangle, int reqursionDeep, int test) {
    if(reqursionDeep >= 5)
        return;

    if(reqursionVecHelper < reqursionDeep) {
        reqursionVec.clear();
        ++reqursionVecHelper;
    }

    glColor3f(1, 0.5, 0.5);
    glBegin(GL_LINE_LOOP);
    for( auto it: triangle.points )
        glVertex2i(it.x(), it.y());
    glEnd();

    std::tuple points = findStartPoint(triangle);
    QPointF minPoint = std::get<0>(points);
    QPointF midPoint = std::get<1>(points);
    QPointF maxPoint = std::get<2>(points);

    QPointF computedPoint_1 = QPointF(maxPoint - QPointF(maxPoint - minPoint)
        / computeLength(maxPoint, minPoint) * computeLength(maxPoint, midPoint) / sqrt(3));
    QPointF computedPoint_2 = (midPoint - minPoint) * -0.5 + midPoint;
    QPointF bisectorPoint = (computedPoint_2 - (computedPoint_2 - midPoint)
        / computeLength(computedPoint_2, midPoint)
        * computeLength(computedPoint_2, computedPoint_1) / sqrt(3));
    QPointF medianPoint = computedPoint_1 - (computedPoint_1 - bisectorPoint) / 2;

    QPointF medianLSPointHelper = computedPoint_1 - (computedPoint_1 - computedPoint_2)
        / computeLength(computedPoint_1, computedPoint_2) *
        computeLength(computedPoint_1, bisectorPoint) / 4 * sqrt(3);

    QPointF medianLSPoint = medianPoint - (medianPoint - medianLSPointHelper)
            / computeLength(medianPoint, medianLSPointHelper)
            * computeLength(computedPoint_1, bisectorPoint) / sqrt(3); // length

    QPointF medianRSPointHelper = computedPoint_1 - (computedPoint_1 - midPoint)
        / computeLength(computedPoint_1, midPoint) *
        computeLength(computedPoint_1, bisectorPoint) / 4 * sqrt(3);

    QPointF medianRSPoint = medianPoint - (medianPoint - medianRSPointHelper)
            / computeLength(medianPoint, medianRSPointHelper)
            * computeLength(computedPoint_1, bisectorPoint) / sqrt(3); // length

    glBegin(GL_LINE_STRIP);
    glVertex2i(midPoint.x(), midPoint.y());
    glVertex2i(computedPoint_1.x(), computedPoint_1.y());
    glVertex2i(computedPoint_2.x(), computedPoint_2.y());
    glEnd();

//    if(reqursionVecHelper == reqursionDeep) {
//        if(test) {
//            reqursionVec.push_back(medianRSPoint);
//            reqursionVec.push_back(medianPoint);
//            reqursionVec.push_back(medianLSPoint);
//        }
//        else {
//            reqursionVec.push_back(medianLSPoint);
//            reqursionVec.push_back(medianPoint);
//            reqursionVec.push_back(medianRSPoint);
//        }
//    }

    if(reqursionVecHelper == reqursionDeep) {
        if(test) {
            tempVec.push_back(medianRSPoint);
            tempVec.push_back(medianPoint);
            tempVec.push_back(medianLSPoint);
        }
        else {
            tempVec.push_back(medianLSPoint);
            tempVec.push_back(medianPoint);
            tempVec.push_back(medianRSPoint);
        }
    }

    drawLogic(Triangle(midPoint, maxPoint, computedPoint_1), reqursionDeep + 1, 1);
    drawLogic(Triangle(midPoint, computedPoint_1, computedPoint_2), reqursionDeep + 1, 0);
    drawLogic(Triangle(computedPoint_2, computedPoint_1, minPoint), reqursionDeep + 1, 1);

    // если test == 0 перевернуть и засунуть в нормальный вектор + это если на предпоследнем уровне
    // reqursionDeep == reqursionVecHelper - 1
    //std::move(tempVec.begin(), tempVec.end(), reqursionVec.end());
    for(const auto& it: tempVec)
        reqursionVec.push_back(it);
    tempVec.clear();
}

void glView::paintGL() {
    qglClearColor(Qt::black);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    QPointF shift = QPointF(50, 50);
    reqursionVecHelper = 0;
    reqursionVec.clear();
    drawLogic(Triangle(QPoint(0, 0) + shift, QPoint(0, 400) + shift, QPoint(693, 400) + shift), 0, 0);

    glBegin(GL_LINE_STRIP);
    glColor3f(0.5, 0.5, 1);
    for(const auto& it: reqursionVec)
        glVertex2i(it.x(), it.y());
    glEnd();
}

void glView::initializeGL() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 600, 0, 0, 1);
}

void glView::resizeGL( int w, int h ) {
    glViewport(0, 0, w, h);
}
