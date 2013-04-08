#define _USE_MATH_DEFINES

#include "GoalRenderer.h"
#include <iostream>
#include <math.h>
#include <QTime>

#define CIRCLE_RADIUS_PER_LEVEL 100

GoalRenderer::GoalRenderer()
{
    // Get random value
    qsrand(QTime::currentTime().msec());
}

void GoalRenderer::setEvent(QPaintEvent* event)
{
	m_pEvent = event;
}

void GoalRenderer::render(GoalElement* ele)
{
    QPainter painter(m_pWidget);
    painter.setRenderHint(QPainter::Antialiasing, true);

    _drawElement(painter, ele);
}

void GoalRenderer::_drawElement(QPainter &painter, GoalElement* ele)
{   
    std::cout << "draing lvl: " << ele->getLevel()
              << " startangle: " << ele->getStartAngle()
              << " endangle: " << ele->getEndAngle() << std::endl;

    int w = m_pWidget->width();
    int h = m_pWidget->height();

    mRectSize = (w > h ? h : w);
    mRadius = CIRCLE_RADIUS_PER_LEVEL * ele->getLevel();
    mRectX = (mRectSize/2) - mRadius;
    mRectY = (mRectSize/2) - mRadius;
    mRectW = mRadius * 2;
    mRectH = mRadius * 2;

    _drawArc(painter, ele);
    _drawArcBorders(painter, ele);
}

void GoalRenderer::_drawArcBorders(QPainter &painter, GoalElement* ele)
{
    if (ele->getLevel() > 1) {
        float x1, x2, y1, y2;
        getCoordsForCircle(mRadius, ele->getStartAngle(), x1, y1);
        getCoordsForCircle(mRadius - CIRCLE_RADIUS_PER_LEVEL, ele->getStartAngle(), x2, y2);

        x1 += mRectSize/2;
        y1 += mRectSize/2;
        x2 += mRectSize/2;
        y2 += mRectSize/2;

        painter.setPen(QPen(QColor(qrand() % 255, qrand() % 255, qrand() % 255), 3));
        painter.drawLine(QPointF(x1, y1), QPointF(x2, y2));
    }
}

void GoalRenderer::_drawArc(QPainter &painter, GoalElement* ele)
{
    // arc
    painter.setPen(QPen(QColor(255, 255, 240), 3));
    QRectF rect(mRectX, mRectY, mRectW, mRectH);
    painter.drawRect(rect); // debug
    painter.setPen(QPen(QColor(255, 0, 0), 3));
    painter.drawArc(rect, 16 * ele->getStartAngle(), 16 * ele->getEndAngle());
}

void GoalRenderer::getCoordsForCircle(float radius, float angle, float& x, float& y)
{
    x = radius * std::cos(2 * M_PI * (angle / 360.0));
    y = radius * std::sin(2 * M_PI * (angle / 360.0));
}

void GoalRenderer::setWidget(QWidget* widget)
{
    m_pWidget = widget;
}
